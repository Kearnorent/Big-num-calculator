#include "operator_type.hh"

operator_type guess_operator_type (const std::string& tok)
{
    if (tok == "+")
        return PLUS;
    else if (tok == "-")
        return MINUS;
    else if (tok == "*")
        return MULT;
    else if (tok == "/")
        return DIV;
    else if (tok == "%")
        return MOD;
    else if (tok == "^")
        return POW;
    return OP_NONE;
}

std::string operator_type_to_string (const operator_type& type)
{
    if (type == PLUS)
        return "+";
    else if (type == MINUS)
        return "-";
    else if (type == MULT)
        return "*";
    else if (type == DIV)
        return "/";
    else if (type == MOD)
        return "%";
    else if (type == POW)
        return "^";
    return "";
}

int operator_type_to_int(const operator_type& type)
{
    if (type == PLUS)
        return 1;
    else if (type == MINUS)
        return 1;
    else if (type == MULT)
        return 2;
    else if (type == DIV)
        return 2;
    else if (type == MOD)
        return 2;
    else if (type == POW)
        return 3;
    return -1;
}