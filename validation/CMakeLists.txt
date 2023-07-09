add_library(Validation src/validate_input.cc)
target_include_directories(Validation PUBLIC 
                    "${PROJECT_SOURCE_DIR}/validation"
                    )