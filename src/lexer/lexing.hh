#pragma once

#include <vector>
#include <iostream>

#include "token.hh"
#include "token_type.hh"
#include "utils/input_error.hh"

namespace lexer
{
    /**
     * @param operation             Input string to tokenize.
     * @return                      Vector of tokens.
     */
    std::vector<lexer::t_token> lex(const std::string& operation);

    /**
     * @param tokens                Vector of tokens to print.
     */
    void pretty_print_tokens (const std::vector<lexer::t_token>& tokens);
}