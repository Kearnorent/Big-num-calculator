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
 * @param type                  The token type
 * @return                      The string matching the token type
 */
std::string tok_type_to_string (const tok_type& type);