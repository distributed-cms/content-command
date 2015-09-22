/*
 * ServerRunner.h
 *
 *  Created on: 22/3/2015
 *      Author: carlos
 */

#ifndef SERVERRUNNER_H_
#define SERVERRUNNER_H_

#include <grpc++/server.h>
#include <grpc++/server_builder.h>
#include <vector>
#include <memory>

namespace content {
	class ServerRunner {
	private:
		std::unique_ptr<grpc::Server> m_server;

	public:
		ServerRunner(const std::string & address, const std::vector<grpc::SynchronousService * > & services);
		virtual ~ServerRunner();

	};
}
#endif /* SERVERRUNNER_H_ */
