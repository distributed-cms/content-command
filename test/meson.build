src = [ 'main.cpp', 'content_cmd_handler_impl_test.cpp' ]

test_name = 'test-content-command'

test_exe = executable(test_name,
                      src,
                      dependencies : lib,
                      link_with : content_cmd_lib)

test(test_name, test_exe)
