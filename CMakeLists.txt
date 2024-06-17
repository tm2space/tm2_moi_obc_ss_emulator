cmake_minimum_required(VERSION 3.18)

project(obc_ss_emulator)

set(SOURCE_FILES main.c)

add_executable(obc_ss_emulator ${SOURCE_FILES} )

target_link_libraries(obc_ss_emulator m zmq)