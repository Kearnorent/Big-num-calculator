#pragma once

#include <memory>
#include <iostream>
#include <vector>
#include <cmath>

#include "lexer/token.hh"

namespace parser
{
    /**
     * @brief                       Class representing the AST that will
     *                              store the operations
     */
    class t_ast
    {
    public:
        t_ast() = default;

        /**
         * @param tok               The token that will represent the AST node
         */
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
     * @param ast                   The AST object to print
     */
    void pretty_print_ast(std::shared_ptr<t_ast> ast, int space, int count);

    /**
     * @param ast                   The AST object to print
     */
    void pretty_print_ast2(std::shared_ptr<t_ast> ast, size_t line_len);
}