cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 0.1.0 LANGUAGES C CXX)
include(CTest)

include(CPack)

enable_testing()

add_subdirectory(src) 

set(CMAKE_CXX_STANDARD 11)



