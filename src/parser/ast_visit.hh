#pragma once

#include <memory>
#include <cmath>

#include "parser/ast.hh"
#include "operations/operations.hh"

namespace visiter
{
    /**
     * @param ast                       The AST object to visit
     */
    void visit (std::shared_ptr<parser::t_ast> ast);

    /**
     * @param operation                 The operation ("+", "-", ...)
     * @param op1                       The first operand of the operation
     * @param op2                       The second operand of the operation
     * @return                          The result of the operation
     */
    std::string calculate (const std::string& operation, std::string op1, std::string op2);

    /**
     * @param ast                       The AST
     */
    void loop_through (std::shared_ptr<parser::t_ast> ast);
}