#pragma once

#include <cstddef>
#include <memory>
#include <vector>

#include "ast.hh"
#include "operator_type.hh"
#include "lexer/token_type.hh"

namespace parser
{
    std::shared_ptr<t_ast> parse (std::vector<lexer::t_token>& tokens, std::string& error_msg);

    void update_the_stacks (std::vector<operator_type>& operator_stack, std::vector<std::shared_ptr<t_ast>>& operand_stack);

    bool is_operator_max_prio (const operator_type& type);

    int compare_priorities (operator_type type1, operator_type type2);
}