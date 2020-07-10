#include "token_type.hh"

std::string tok_type_to_string (const tok_type& type)
{
    std::string res;
    switch (type)
    {
        case NONE:
            break;
        case NUMBER:
            res = "(Number)";
            break;
        case OPERATOR:
            res = "(Operator)";
            break;
        case LEFT_PAR:
            res = "(Left parenthesis)";
            break;
        case RIGHT_PAR:
            res = "(Right parenthesis)";
            break;
    }
    return res;
}