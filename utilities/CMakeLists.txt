
add_library(Utilities src/reader.cc)
target_include_directories(Utilities PUBLIC 
                    "${PROJECT_SOURCE_DIR}/utilities"
                    "${PROJECT_SOURCE_DIR}/io")
                    