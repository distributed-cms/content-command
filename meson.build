project('content-command', 'cpp')
add_global_arguments('-std=c++14', language : 'cpp')

name = 'content-command'

#Dependencies
lib = [
  find_library('zmq'),
  find_library('grpc++'),
  find_library('grpc'),
  find_library('protobuf'),
  find_library('gpr'),
  find_library('pthread'),
  find_library('dl')]

# Subdirectories
subdir('src')
subdir('test')

# Package config
pkgconfig_gen(
  version : '1.0',
  name : name,
  filebase : name,
  description : 'content command server')

#rpm = import('rpm')
#rpm.generate_spec_template()
