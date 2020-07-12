#include "operations.hh"

namespace operations
{
    std::string division(std::string n1, std::string n2, int base)
    {
        if (n1[0] == '-' and n2[0] == '-')
            return division(n1.substr(1), n2.substr(1), base);
        else if (n1[0] == '-')
            return division(n1.substr(1), n2, base);
        else if (n2[0] == '-')
            return division(n1, n2.substr(1), base);

        std::string res;
        std::string temp = n1;
        while (temp[0] != '-')
        {
            temp = visiter::calculate("-", temp, n2);
            res = visiter::calculate("+", res, "1");
        }
        return visiter::calculate("-", res, "1");
    }
}