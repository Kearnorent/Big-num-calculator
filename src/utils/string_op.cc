#include "string_op.hh"

void remove_useless_characters (std::string& str)
{
    std::string new_string;
    size_t len = str.size();
    for (size_t i = 0; i < len; ++i)
    {
        if (not is_whitespace(str[i]))
            new_string += str[i];
    }
    str = new_string;
}