#pragma once
#include <input.h>
#include <vector>
namespace utilities
{
    io::input read_input_file(const char* path_to_file);

    std::vector<io::input> read_input_directory(const char* directory);
}    

