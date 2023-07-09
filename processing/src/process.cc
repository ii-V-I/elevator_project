#include <process.h>
#include <input.h>
#include <string>
#include <algorithms.h>
#include <random>
#include <reader.h>

processor::processor() : time("10") {}
processor::~processor() {}
io::output processor::input_to_output(io::input input)
{
    int total_travel_time = algorithms::get_path_travel_time(input.get_time(), input.get_floors());
    return io::output(total_travel_time, input.get_floors());
}

std::vector<io::output> floor_processing::process(char *args[])
{
    io::input input(args[2], args[3], this->time.c_str());
    return vector<io::output>{ this->input_to_output(input) };
}

std::vector<io::output> floor_rand_processing::process(char *args[])
{
    int min = std::stoi(args[2]), max = std::stoi(args[3]), num_changes = std::stoi(args[4]);

    std::string str;
    int start = 0;
    for (int i = 0; i < num_changes; ++i)
    {
        int output = min + (rand() % static_cast<int>(max - min + 1));
        if (i == 0)
        {
            start = output;
            continue;
        }
        if (i == num_changes - 1)
            str += std::string(std::to_string(output));
        else
            str += std::string(std::to_string(output)) + ",";
    }

    io::input input(args[2], str.c_str(), this->time.c_str());
    return vector<io::output>{ this->input_to_output(input) };
}


std::vector<io::output> path_processing::process(char* args[])
{
    std::vector<io::input> inputs = utilities::read_input_directory(args[2]);
    std::vector<io::output> processed_inputs;
    for (io::input i : inputs)
        processed_inputs.push_back(this->input_to_output(i));  
    return processed_inputs;
}

std::unique_ptr<processor> processor_factory::create_processor(valid_inputs input)
{
    switch (input)
    {
    case valid_inputs::floor:
        return std::make_unique<floor_processing>();
        break;

    case valid_inputs::floor_rand:
        return std::make_unique<floor_rand_processing>();
        break;

    case valid_inputs::path:
        return std::make_unique<path_processing>();
        break;
    
    default:
        return std::unique_ptr<floor_processing>();
        break;
    }
}
