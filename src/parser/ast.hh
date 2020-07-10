#pragma once

#include <memory>

#include "lexer/token.hh"

namespace parser
{
    class t_ast
    {
    public:
        t_ast() = default;

        t_ast(const lexer::t_token& tok);
    private:
        lexer::t_token token;
        std::shared_ptr<t_ast> left;
        std::shared_ptr<t_ast> right;
    };
}