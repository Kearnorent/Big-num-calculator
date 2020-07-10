#pragma once

#include <cstddef>
#include <memory>
#include <vector>

#include "ast.hh"
#include "operator_type.hh"
#include "lexer/token_type.hh"

namespace parser
{
    /**
     * @param tokens
     * @param error_msg
     * @return
     */
    std::shared_ptr<t_ast> parse (std::vector<lexer::t_token>& tokens, std::string& error_msg);

    /**
     * @param tokens
     * @param ind
     * @param shift
     * @return
     */
    std::vector<lexer::t_token> get_tokens_between_pars(std::vector<lexer::t_token>& tokens, size_t ind, size_t& shift);
}