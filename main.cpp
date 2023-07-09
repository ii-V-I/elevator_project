#include <iostream>
#include <reader.h>
#include <algorithms.h>
#include <validate_input.h>
#include <random>
#include <vector>
#include <process.h>

/* 
    See README for command list
*/
int main(int i, char* args[])
{
    if (i <= 1)
    {
        std::cout << "Not enough input arguements given" << std::endl;
        return -1;
    }

    // validate that the input is a valid command
    char* requested_action = args[1];
    valid_inputs input  = validate_input::validate(requested_action);

    // If a processor exists for that command get it. 
    // I use a unique_ptr here to avoid object slicing when using an abstract class. 
    // A unique_ptr also prevents memory leaks.
    std::unique_ptr<processor> processor = processor_factory::create_processor(input);
    if(!processor.get())
    {
        std::cout << "Processor not created" << std::endl;
        if (input == valid_inputs::invalid)
            std::cout << "Because invalid command given" << std::endl;
        return -1;
    }

    // run the associated processing with a given input.
    std::vector<io::output> outputs = processor.get()->process(args);

    // print the results of the processing.
    for (io::output o : outputs)
        o.print();

    return 0;
}