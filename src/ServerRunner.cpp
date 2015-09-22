

#include <iostream>
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
	  m_server = builder.BuildAndStart();

	  LOG(INFO) << address << ": Server listening";

	  m_server->Wait();
}

ServerRunner::~ServerRunner()
{
	  m_server->Shutdown();
	  LOG(INFO) << "Server stopped";
}
}
