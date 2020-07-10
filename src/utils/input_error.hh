#pragma once

#include <cstddef>
#include <string>

/**
 * @param param             String given as parameter.
 * @return                  True if 'param' is a valid operation, False otherwise.
 */
bool is_valid_operation (const char* param, std::string& error_msg);

/**
 * @param cur               A character.
 * @return                  True if 'cur' is a number, False otherwise.
 */
bool is_number(const char& cur);

/**
 * @param cur               A character.
 * @return                  True if 'cur' is a whitespace character, False otherwise.
 */
bool is_whitespace(const char& cur);

/**
 * @param cur               A character.
 * @return                  True if 'cur' is a parenthesis character, False otherwise.
 */
bool is_parenthesis(const char& cur);

/**
 * @param cur               A character.
 * @return                  True if 'cur' is an operator character, False otherwise.
 */
bool is_operator(const char& cur);