#pragma once

#include <memory>
#include <cmath>

#include "parser/ast.hh"
#include "operations/operations.hh"

namespace visiter
{
    /**
     * @param ast
     */
    void visit (std::shared_ptr<parser::t_ast> ast);

    /**
     * @param operation
     * @param op1
     * @param op2
     * @return
     */
    std::string calculate (const std::string& operation, const std::string& op1, const std::string& op2);

    /**
     * @param ast
     */
    void loop_through (std::shared_ptr<parser::t_ast> ast);
}