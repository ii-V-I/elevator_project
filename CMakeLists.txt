cmake_minimum_required(VERSION 3.10)

# need to set minimum C++ version to 17 for file system. 
# set the project name and version
project(elevator VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(validation)
add_subdirectory(utilities)
add_subdirectory(io)
add_subdirectory(algorithms)
add_subdirectory(processing)
# add the executable
add_executable(elevator main.cpp)

target_link_libraries(elevator PUBLIC 
                                    Utilities
                                    IO
                                    Algorithms
                                    Validation
                                    Processing)


