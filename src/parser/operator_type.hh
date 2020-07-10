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

/**
 * @param tok
 * @return
 */
operator_type guess_operator_type (const std::string& tok);

/**
 * @param type
 * @return
 */
std::string operator_type_to_string (const operator_type& type);

/**
 * @brief Returns the priorities for each operator (the higher to more prioritary)
 * @param type
 * @return
 */
int operator_type_to_int (const operator_type& type);