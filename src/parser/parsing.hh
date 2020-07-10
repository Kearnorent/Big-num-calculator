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
}