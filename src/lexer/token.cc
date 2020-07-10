#include "token.hh"

namespace lexer
{
    t_token::t_token (const std::string& val, const tok_type& tok_type)
        :   value(val),
            token_type(tok_type)
    {
    }
}