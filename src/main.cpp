#include <iostream>
#include <memory>
#include <string>

#include <grpc/grpc.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/credentials.h>
#include <grpc++/channel_arguments.h>

#include <csignal>

#include "ContentCmdHandlerImpl.h"
#include "eventstore.grpc.pb.h"
#include "ServerRunner.h"
#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

using namespace std;
using namespace content;
using namespace event;
using namespace grpc;

void help(char * programName)
{
	cout << "Help:\n\t" << programName << " hostname:port" << endl;
}

void exitApp()
{
	LOG(INFO) << "Exiting";

	grpc_shutdown();

	LOG(INFO) << "GRPC stopped";
}

void exitHandler(int signal)
{
	exitApp();

	exit(0);
}

int main(int argc, char** argv) {

	if (argc < 2) {
		help(argv[0]);
	}
	else {
		signal(SIGINT, exitHandler);

		START_EASYLOGGINGPP(argc, argv);

		grpc_init();

		LOG(INFO) << "GRPC initialized";

// TODO wrap the stub using interface EventStore
		unique_ptr<EventStore::Stub> eventStoreStub = EventStore::NewStub(
		    CreateChannel(
			  	"localhost:50051",
			  	InsecureCredentials(),
				ChannelArguments()
			)
		);
		ContentCmdHandlerImpl content_cmd_handler{eventStoreStub.get()};

		ServerRunner server_runner {argv[1], {&content_cmd_handler}};

		exitApp();
	}


	return 0;
}
