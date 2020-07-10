#pragma once

#include <memory>
#include <iostream>

#include "lexer/token.hh"

namespace parser
{
    class t_ast
    {
    public:
        t_ast() = default;

        t_ast(const lexer::t_token& tok);

        lexer::t_token get_token() { return token; }

        void set_token (const lexer::t_token& tok) { token = tok; }

        /// Public attributes.
        std::shared_ptr<t_ast> left;
        std::shared_ptr<t_ast> right;
    private:
        /// Private attributes.
        lexer::t_token token;
    };

    /**
     * @param ast
     */
    void pretty_print_ast(std::shared_ptr<t_ast> ast, int space, int count);
}