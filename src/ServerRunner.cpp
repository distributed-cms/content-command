

#include <iostream>
#include <memory>
#include <grpc++/server.h>
#include <grpc++/server_builder.h>
#include <grpc++/server_context.h>
#include <grpc++/server_credentials.h>
#include "ServerRunner.h"
#include "easylogging++.h"

namespace content {

using namespace std;
using namespace grpc;

ServerRunner::ServerRunner(const string & address, const vector<SynchronousService *> & services)
{
	  ServerBuilder builder;

	  builder.AddListeningPort(address, grpc::InsecureServerCredentials());
	  for (auto s : services){
		  builder.RegisterService(s);
	  }
	  unique_ptr<Server> server(builder.BuildAndStart());

	  LOG(INFO) << address << ": Server listening";

	  server->Wait();
}

}
