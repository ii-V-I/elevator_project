add_library(Processing src/process.cc)
target_include_directories(Processing PUBLIC 
                            "${PROJECT_SOURCE_DIR}/io"
                            "${PROJECT_SOURCE_DIR}/algorithms"
                            "${PROJECT_SOURCE_DIR}/utilities"
                            "${PROJECT_SOURCE_DIR}/processing"
                            "${PROJECT_SOURCE_DIR}/validation")   