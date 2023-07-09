#include <validate_input.h>
#include <string>

const char* validate_input::valid_actions[4] =
            {
                "--floors",
                "--floors-rand",
                "--path",
                "--interactive"
            };

valid_inputs validate_input::validate(const char* action)
{
    for (int n = 0; n < 4; ++n)
        if(strcmp(action, valid_actions[n]) == 0)
            return (valid_inputs)(n + 1);
    return valid_inputs::invalid;
}