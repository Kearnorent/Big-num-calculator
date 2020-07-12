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
     * @param tokens                        The vector of tokens
     * @param error_msg                     The error msg to fill in case an error happens
     * @return                              The final AST built from the tokens
     */
    std::shared_ptr<t_ast> parse (std::vector<lexer::t_token>& tokens, std::string& error_msg);

    /**
     * @param tokens                        The vector of tokens containing parenthesis
     * @param ind                           The index of the opening parenthesis
     * @param shift                         The index of the right closing parenthesis
     * @return                              The tokens between the opening and closing parentheses.
     */
    std::vector<lexer::t_token> get_tokens_between_pars(std::vector<lexer::t_token>& tokens, size_t ind, size_t& shift);
}