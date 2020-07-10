#include "ast.hh"

namespace parser
{
    t_ast::t_ast(const lexer::t_token& tok)
        :   token(tok),
            left(nullptr),
            right(nullptr)
    {
    }
}