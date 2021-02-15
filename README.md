# Overview
This repo contains a minimal example of how cmock generates the wrong include paths for mocked files when `:treat_inlines: :include` is turned on

Run `./ceedling` to execute the local build. Note how `build/mocks/fsl_flexspi.h` has `#include "common/hal/fsl_common.h"` rather than `#include "fsl_common.h"`. This breaks things because `common/**` is on the include path, and not the root of the project. 

```
Test 'test_proto_flash.c'                                                                                                                                                            
-------------------------                                                                                                                                                            
Generating include list for fsl_flexspi.h...                                                                                                                                         
Creating mock for fsl_flexspi...                                                                                                                                                     
In file included from build/test/mocks/mock_fsl_flexspi.h:6,                                                                                                                         
                 from test/common/proto/test_proto_flash.c:4:                                                                                                                        
build/test/mocks/fsl_flexspi.h:1:10: fatal error: common/hal/fsl_common.h: No such file or directory                                                                                 
    1 | #include "common/hal/fsl_common.h"                                                                                                                                           
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~                                                                                                                                           
compilation terminated.                                                                                                                                                              
ERROR: Shell command failed.                                                                                                                                                         
> Shell executed command:                                                                                                                                                            
'gcc -E -I"/home/brett/workspace/firmware/sandbox/cmock-include-bug/vendor/ceedling/vendor/unity/src" -I"/home/brett/workspace/firmware/sandbox/cmock-include-bug/vendor/ceedling/ven
dor/cmock/src" -I"build/test/mocks" -I"test" -I"test/common" -I"test/common/proto" -I"common" -I"common/hal" -I"common/proto" -DCPU_MIMXRT1051DVL6B -DTEST -DUNITY_INCLUDE_PRINT_FORM
ATTED -DCPU_MIMXRT1051DVL6B -DTEST -DGNU_COMPILER "test/common/proto/test_proto_flash.c" -o "build/test/preprocess/files/test_proto_flash.c"'                                        
> And exited with status: [1].                                                                                                                                                       
                                                                                                                                                                                     
rake aborted!                                                                                                                                                                        
ShellExecutionException: ShellExecutionException
/home/brett/workspace/firmware/sandbox/cmock-include-bug/vendor/ceedling/lib/ceedling/tool_executor.rb:88:in `exec'
/home/brett/workspace/firmware/sandbox/cmock-include-bug/vendor/ceedling/lib/ceedling/preprocessinator_file_handler.rb:12:in `preprocess_file'
/home/brett/workspace/firmware/sandbox/cmock-include-bug/vendor/ceedling/lib/ceedling/preprocessinator.rb:48:in `preprocess_file'
/home/brett/workspace/firmware/sandbox/cmock-include-bug/vendor/ceedling/lib/ceedling/preprocessinator.rb:12:in `block in setup'
/home/brett/workspace/firmware/sandbox/cmock-include-bug/vendor/ceedling/lib/ceedling/preprocessinator_helper.rb:37:in `preprocess_test_file'
/home/brett/workspace/firmware/sandbox/cmock-include-bug/vendor/ceedling/lib/ceedling/preprocessinator.rb:33:in `preprocess_test_and_invoke_test_mocks'
/home/brett/workspace/firmware/sandbox/cmock-include-bug/vendor/ceedling/lib/ceedling/test_invoker.rb:84:in `block in setup_and_invoke'
/home/brett/workspace/firmware/sandbox/cmock-include-bug/vendor/ceedling/lib/ceedling/test_invoker.rb:51:in `setup_and_invoke'
/home/brett/workspace/firmware/sandbox/cmock-include-bug/vendor/ceedling/lib/ceedling/tasks_tests.rake:13:in `block (2 levels) in <top (required)>'
/var/lib/gems/2.7.0/gems/ceedling-0.31.0/bin/ceedling:345:in `block in <top (required)>'
/var/lib/gems/2.7.0/gems/ceedling-0.31.0/bin/ceedling:332:in `<top (required)>'
/usr/local/bin/ceedling:23:in `load'
/usr/local/bin/ceedling:23:in `<main>'
Tasks: TOP => default => test:all
(See full trace by running task with --trace) 
ERROR: Ceedling Failed
```

I cannot put the root of the project as an include directory, or ceedling will complain about too long of an include path (the real project has many thousands of files...)

# Files
```
.
├── common
│   ├── hal
│   │   ├── fsl_common.h   // bad path generated for this file
│   │   ├── fsl_flexspi.c  
│   │   └── fsl_flexspi.h  // includes fsl_common.h
│   └── proto
│       ├── proto_flash.c  // includes fsl_flexspi.h
│       └── proto_flash.h
├── project.yml
└── test
    ├── common
    │   └── proto
    │       └── test_proto_flash.c   // this is the test that breaks things

```
