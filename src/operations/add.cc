#include "operations.hh"

namespace operations
{
    std::string addition(std::string n1, std::string n2, int base)
    {
        /// Input cases
        if (n1[0] == '-')
            return visiter::calculate("-", n2, n1.substr(1));
        else if (n2[0] == '-')
            return visiter::calculate("-", n1, n2.substr(1));

        std::string res(n1.size() + 1, ' ');
        int retenue = 0;
        for (int i = n1.size() - 1; i >= 0; --i)
        {
            int cur = (n1[i] - '0') + (n2[i] - '0');
            res[i + 1] = (cur + retenue) % base + '0';
            retenue = (cur + retenue) / base;
        }
        res[0] = retenue + '0';
        return res;
    }
}