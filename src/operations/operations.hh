#pragma once

#include <iostream>
#include <string>

#include "parser/ast_visit.hh"
#include "utils/string_op.hh"

extern int base;

namespace operations
{
    /**
     * @param n1
     * @param n2
     * @return
    */
    std::string addition(std::string n1, std::string n2);

    /**
     * @param n1
     * @param n2
     * @return
    */
    std::string subtraction(std::string n1, std::string n2);

    /**
     * @param n1
     * @param n2
     * @return
    */
    std::string multiplication(std::string n1, std::string n2);

    /**
     * @param n1
     * @param n2
     * @return
    */
    std::string division(std::string n1, std::string n2);

    /**
     * @param n1
     * @param n2
     * @return
    */
    std::string modulo(std::string n1, std::string n2);

    /**
     * @param n1
     * @param n2
     * @return
    */
    std::string power(std::string n1, std::string n2);
}