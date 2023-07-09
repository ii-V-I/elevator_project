add_library(IO src/input.cc src/output.cc)
target_include_directories(IO PUBLIC 
                            "${PROJECT_SOURCE_DIR}/io")         