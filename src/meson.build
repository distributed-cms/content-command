project('content-command', 'cpp')
add_global_arguments('-std=c++14', language : 'cpp')

#Dependencies
LIBRARIES = [find_library('zmq'), find_library('grpc++'), find_library('grpc'), find_library('gpr'), find_library('protobuf'), find_library('pthread'), find_library('dl')]

#Executables
executable('content-command', 'main.cpp', 'ServerRunner.cpp', 'ContentCmdHandlerImpl.cpp','base.grpc.pb.cc', 'base.pb.cc', 'content.grpc.pb.cc', 'content.pb.cc','eventstore.grpc.pb.cc', 'eventstore.pb.cc', dependencies : LIBRARIES)

# Tests
#uuid_test = executable('uuid_test', 'test/uuid_test.cpp', 'Uuid.cpp')
#test('uuid test', uuid_test)
