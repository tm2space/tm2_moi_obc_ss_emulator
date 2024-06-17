# TM2Space MOI-TD OBC Sensor Stream Emulator

## Installation

use the following commands for OSX

```bash
$ brew install zmq
$ brew install czmq
```

use the following commands for Linux (Ubuntu/Debian/Mint)

```bash
$ apt-get install libzmq3-dev
$ apt-get install libczmq-dev
```

## Build Process
After you download the code, open terminal in that folder and run the following commands

```bash
$ cmake CMakeLists.txt
```

You should see CMakeFiles folder and Makefile getting created. Run the next command to build the final executable.

```bash
$ make
```