#include "operations.hh"

namespace operations
{
    std::string subtraction(std::string n1, std::string n2, int base)
    {
        /// Input cases
        if (n1[0] != '-' and n2[0] == '-')
            return visiter::calculate("+", n1, n2.substr(1));
        else if (n1[0] == '-' and n2[0] != '-')
            return "-" + visiter::calculate("+", n1.substr(1), n2);
        else if (n1[0] == '-' and n2[0] == '-')
        {
            n1 = n1.substr(1);
            n2 = n2.substr(1);
            std::string swp = n1;
            n1 = n2;
            n2 = swp;
        }

        if (n1.compare(n2) < 0)
            return "-" + visiter::calculate("-", n2, n1);
        std::string res;
        int retenue = 0;
        for (int i = n1.size() - 1; i >= 0; --i)
        {
            int dig1 = n1[i] - '0';
            int dig2 = n2[i] - '0' + retenue;
            if (dig1 >= dig2)
            {
                retenue = 0;
                res.insert(0, std::to_string(dig1 - dig2));
            }
            else
            {
                retenue = 1;
                res.insert(0, std::to_string((dig1 + base) - dig2));
            }
        }
        return res;
    }
}