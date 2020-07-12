#pragma once

#include <cstddef>
#include "input_error.hh"

/**
 * @brief                   Removes useless characters (whitespaces, ...)
 * @param str               Input string representing the operation.
 */
void remove_useless_characters (std::string& str);

/**
 * @brief                   Adds zeroes before negated numbers ("1+-3" becomes "1+0-3")
 * @param str               The string to modify (representing the operation)
 */
void add_zeroes (std::string& str);

/**
 * @brief                   Removes the padding zeroes at the start of the operation string
 * @param str               The string to modify (representing the operation)
 */
void remove_zeroes (std::string& str);