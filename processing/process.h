#pragma once

#include <valid_inputs.h>
#include <memory>
#include <vector>
#include <string>
#include <output.h>
#include <input.h>

class processor
{
protected:
    std::string time;
    processor();
    io::output input_to_output(io::input input);
public:
    virtual std::vector<io::output> process(char *args[]) = 0;
    virtual ~processor();
};

class floor_processing : public processor
{
public:
    std::vector<io::output> process(char *args[]) override;
};

class floor_rand_processing : public processor
{
public:
    std::vector<io::output> process(char *args[]) override;
};

class path_processing : public processor
{
public:
    std::vector<io::output> process(char *args[]) override;
};

class processor_factory
{

public:
    static std::unique_ptr<processor> create_processor(valid_inputs input);
};
