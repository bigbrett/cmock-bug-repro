# Overview
This repo contains a minimal example of how cmock generates the wrong include paths for mocked files when `:treat_inlines: :include` is turned on


```
.
├── app
│   └── myapp
│       └── main.c
├── ceedling
├── common
│   ├── hal
│   │   ├── fsl_common.h
│   │   ├── fsl_flexspi.c
│   │   └── fsl_flexspi.h
│   └── proto
│       ├── proto_flash.c
│       └── proto_flash.h
├── project.yml
├── tags
└── test
    ├── common
    │   ├── hal
    │   │   └── test_fsl_flexspi.c
    │   └── proto
    │       └── test_proto_flash.c   // this is the test that breaks things1G


```
