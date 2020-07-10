#pragma once

#include <memory>
#include <cmath>

#include "parser/ast.hh"

namespace visiter
{
    void visit (std::shared_ptr<parser::t_ast> ast);

    std::string calculate (const std::string& operation, const std::string& op1, const std::string& op2);

    void loop_through (std::shared_ptr<parser::t_ast> ast);
}