#pragma once
#include <valid_inputs.h>

class validate_input
{
    static const char *valid_actions[];

public:
    validate_input() = delete;

    static valid_inputs validate(const char *action);
};
