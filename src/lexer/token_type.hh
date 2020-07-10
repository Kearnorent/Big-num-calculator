#pragma once

#include <string>

enum tok_type
{
    NONE,
    NUMBER,
    OPERATOR,
    LEFT_PAR,
    RIGHT_PAR,
};

/**
 * @param type
 * @return
 */
std::string tok_type_to_string (const tok_type& type);