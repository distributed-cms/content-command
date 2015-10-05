
#include "catch.hpp"
#include "../src/ContentCmdHandlerImpl.h"
#include "../src/eventstore.grpc.pb.h"

using namespace content;

class EventStore : public event::EventStore::StubInterface {
    private:
        virtual ::grpc::ClientReaderInterface< ::common::Event>* get_eventsRaw(::grpc::ClientContext* context, const ::common::Uuid& request)
        {
            return nullptr;
        };

        virtual ::grpc::ClientAsyncReaderInterface< ::common::Event>* Asyncget_eventsRaw(::grpc::ClientContext* context, const ::common::Uuid& request, ::grpc::CompletionQueue* cq, void* tag)
        {
            return nullptr;
        };
};


TEST_CASE( "Init Content Cmd Handler Impl", "[ContentCmdHandlerImpl]" ) {

    ContentCmdHandlerImpl cchi{ new EventStore{} };
    REQUIRE(1 == 2 );
}
