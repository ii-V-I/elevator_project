
#include <reader.h>
#include <fstream>
#include <filesystem>
#include <string>

io::input utilities::read_input_file(const char* path_to_file)
{
    // create and check file. return blank object if invalid.
    std::ifstream file(path_to_file);
    if (!file.is_open())
        return io::input();

    // a valid file in this scenario is 3 lines
    const int valid_lines = 3;
    std::string lines[valid_lines];

    // read each line while file is valid
    for (int i = 0; i < valid_lines && file.good(); ++i)
        std::getline(file, lines[i]);
    
    return io::input(lines[0].c_str(), lines[1].c_str(), lines[2].c_str());
}

std::vector<io::input> utilities::read_input_directory(const char* directory)
{
    std::vector<io::input> files;
    for (const std::filesystem::directory_entry & entry : std::filesystem::directory_iterator(directory))
        files.push_back(read_input_file(entry.path().c_str()));
    return files;
}