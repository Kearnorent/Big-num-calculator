#include "input_error.hh"

bool is_valid_operation (const char* param, std::string& error_msg)
{
    for (size_t i = 0; param[i]; ++i)
    {
        if (not is_number(param[i])
        and not is_operator(param[i])
        and not is_whitespace(param[i]))
        {
            std::string cur_char = std::string(1, param[i]);
            error_msg = "Not valid character : \'" + cur_char + "\'";
            return false;
        }
    }
    return true;
}

bool is_number(const char& cur)
{
    if (cur <= '0' or cur >= '9')
        return false;
    return true;
}

bool is_whitespace(const char& cur)
{
    if (cur == ' ' or cur == '\t')
        return true;
    return false;
}

bool is_operator(const char& cur)
{
    char op[] = {'+', '-', '/', '*', '%','^', '(', ')', '\0'};
    for (int i = 0; op[i]; ++i)
    {
        if (cur == op[i])
            return true;
    }
    return false;
}