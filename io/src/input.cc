#include <input.h>
#include <iostream>
io::input::input(){}

io::input::input(const char* start, const char* floors,  const char* time)
{
    int start_index;
    sscanf(start, "%d", &start_index);
  
    if (start_index >= 1 && start_index <= 124)
        this->floors.push_back(start_index);

    io::input::parse_floor(floors, this->floors);
    sscanf(time, "%d", &this->time);
}

void io::input::parse_floor(const char* line, std::vector<int>& floors)
{
    std::string str_line(line);
    int start_index = str_line.find(":") + 1;
    
    while (start_index < str_line.size())
    {
        std::size_t index = str_line.find(',', start_index);
        
        if (index == std::string::npos)    
            index = str_line.size();
    

        std::string number = str_line.substr(start_index, index - start_index);
        int floor = std::stoi(number);
        // must be great than or equal to 1 and shorter than the world's
        // tallest elevator at approximately 124 floors in the Shanghai Tower
        // in China
        if (floor >= 1 && floor <= 124)
            floors.push_back(floor);

        start_index = index + 1;
    }
}

int io::input::get_start()
{
    if (this->floors.size() < 1)
        return -1;
    return this->floors[0];
}

const vector<int>& io::input::get_floors()
{
    return this->floors;
}

int io::input::get_time()
{
    return this->time;
}

void io::input::print()
{
    std::cout << "starting floor: " << this->get_start() << std::endl;
    const vector<int>& floors = this->get_floors();
    
    std::cout << "floor(s): ";
    for (int i = 0; i < this->get_floors().size(); ++i)
        std::cout << this->get_floors()[i] << " ";
    std::cout << "" << std::endl;

    std::cout << "time constant: " << this->get_time() << std::endl;
}
