#pragma once

#include <string>

enum operator_type
{
    OP_NONE,
    PLUS,
    MINUS,
    MULT,
    DIV,
    MOD,
    POW,
};

operator_type guess_operator_type (const std::string& tok);

std::string operator_type_to_string (const operator_type& type);

/// Returns the priorities for each operator (the higher to more prioritary)
int operator_type_to_int (const operator_type& type);