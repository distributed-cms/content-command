#include <iostream>
#include <memory>
#include <string>

#include <grpc/grpc.h>

#include "ContentCmdHandlerImpl.h"
#include "ServerRunner.h"
#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

using namespace std;
using namespace content;

void help(char * programName)
{
	cout << "Help:\n\t" << programName << " hostname:port" << endl;
}

int main(int argc, char** argv) {

	if (argc < 2) {
		help(argv[0]);
	}
	else {
		START_EASYLOGGINGPP(argc, argv);

		grpc_init();

		LOG(INFO) << "GRPC initialized";

		ContentCmdHandlerImpl content_cmd_handler{};

		ServerRunner server_runner {argv[1], {&content_cmd_handler}};

		grpc_shutdown();

		LOG(INFO) << "GRPC stopped";
	}


	return 0;
}
