
src = [ 'ServerRunner.cpp',
        'ContentCmdHandlerImpl.cpp',
        'base.grpc.pb.cc', 'base.pb.cc',
        'content.grpc.pb.cc', 'content.pb.cc',
        'eventstore.grpc.pb.cc', 'eventstore.pb.cc' ]

content_cmd_lib = static_library(name, src,
                        dependencies : lib,
                        install : false)

executable(name, 'main.cpp', link_with: content_cmd_lib,  dependencies : lib, install : true)
