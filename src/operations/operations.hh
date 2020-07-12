#pragma once

#include <iostream>
#include <string>

#include "parser/ast_visit.hh"
#include "utils/string_op.hh"

/// 'base' Global variable
extern int base;

namespace operations
{
    /**
     * @param n1                    First number
     * @param n2                    Second number
     * @return                      The result of the addition of n1 and n2 (n1 + n2)
    */
    std::string addition(std::string n1, std::string n2);

    /**
     * @param n1                    First number
     * @param n2                    Second number
     * @return                      The result of the subtraction of n1 and n2 (n1 - n2)
    */
    std::string subtraction(std::string n1, std::string n2);

    /**
     * @param n1                    First number
     * @param n2                    Second number
     * @return                      The result of the multiplication of n1 and n2 (n1 * n2)
    */
    std::string multiplication(std::string n1, std::string n2);

    /**
     * @param n1                    First number
     * @param n2                    Second number
     * @return                      The result of the division of n1 and n2 (n1 / n2)
    */
    std::string division(std::string n1, std::string n2);

    /**
     * @param n1                    First number
     * @param n2                    Second number
     * @return                      The result of n1 modulo n2 (n1 % n2)
    */
    std::string modulo(std::string n1, std::string n2);

    /**
     * @param n1                    First number
     * @param n2                    Second number
     * @return                      The result of n1 power n2 (n1 ^ n2)
    */
    std::string power(std::string n1, std::string n2);
}