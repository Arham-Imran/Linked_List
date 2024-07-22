cmake_minimum_required(VERSION 3.5.0)
project(Linked_List VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(./timing)
add_executable(Linked_List main.cpp)

target_link_libraries(Linked_List 
        PUBLIC 
        timing
        )
add_compile_options("-Wall")