#include "operations.hh"

namespace operations
{
    std::string power(std::string n1, std::string n2)
    {
        std::string res = "1";
        std::string counter = "0";
        std::string cond;
        while (cond != "0")
        {
            res = visiter::calculate("*", res, n1);
            counter = visiter::calculate("+", counter, "1");
            cond = visiter::calculate("-", n2, counter);
            remove_zeroes(cond);
        }
        return res;
    }
}