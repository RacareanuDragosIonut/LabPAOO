add_executable(MyProject main.cpp)
add_library(AccountLib Account.cpp Account.hpp)
target_include_directories(AccountLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(MyProject PRIVATE AccountLib)

