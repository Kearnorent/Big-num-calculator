#pragma once

#include <string>

#include "token_type.hh"

namespace lexer
{
    class t_token
    {
    public:
        t_token () = default;

        /**
         * @param val
         * @param tok_type
         */
        t_token (const std::string& val, const tok_type& tok_type);

        std::string get_value () { return value; };
        tok_type get_type () { return token_type; };
    private:
        std::string value;
        tok_type token_type;
    };
}