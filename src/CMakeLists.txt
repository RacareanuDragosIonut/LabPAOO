add_executable(MyProject main.cpp)
add_subdirectory(Account)
add_subdirectory(SavingsAccount)
target_link_libraries(MyProject PRIVATE Account SavingsAccount)



