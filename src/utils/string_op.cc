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

void add_zeroes (std::string& str)
{
    std::string new_string;
    int count_ope = 0;
    int count_nb = 0;
    for (int i = 0; str[i]; ++i)
    {
        if (is_number(str[i]))
        {
            count_nb += 1;
            count_ope = 0;
        }
        else if (is_operator(str[i]))
            count_ope += 1;

        if (count_ope == 2 or (count_nb == 0 and count_ope == 1))
            new_string += '0';
        new_string += str[i];
    }
    str = new_string;
}