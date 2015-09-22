/*
 * ContentCmdHandlerImpl.cpp
 *
 *  Created on: 22/3/2015
 *      Author: carlos
 */

#include "ContentCmdHandlerImpl.h"
#include "easylogging++.h"


namespace content {

using grpc::ServerContext;
using grpc::Status;

using namespace std;
using namespace common;

ContentCmdHandlerImpl::ContentCmdHandlerImpl() {
}

ContentCmdHandlerImpl::~ContentCmdHandlerImpl (){

}

Status ContentCmdHandlerImpl::save (ServerContext* context, const Content* request, CmdResponse* response){
	LOG(INFO) << "Save";

	return Status::OK;
}

Status ContentCmdHandlerImpl::remove (ServerContext* context, const Uuid* request, CmdResponse* response){
	LOG(INFO) << "Remove";

	return Status::OK;
}

Status ContentCmdHandlerImpl::removePart (ServerContext* context, const Uuid* request, CmdResponse* response){
	LOG(INFO) << "Remove part";

	return Status::OK;
}

Status ContentCmdHandlerImpl::updatePart (ServerContext* context, const UpdatePart* request, CmdResponse* response){
	LOG(INFO) << "Update part";

	return Status::OK;
}

}
