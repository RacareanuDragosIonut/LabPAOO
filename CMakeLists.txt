cmake_minimum_required(VERSION 3.10)
project(MyProject)


add_executable(build src/main.cpp src/Account.cpp src/Account.hpp)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)


