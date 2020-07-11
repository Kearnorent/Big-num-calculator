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

        std::string res;
        int retenue = 0;
        for (int i = n1.size() - 1; i >= 0; --i)
        {
            int cur = (n1[i] - '0') + (n2[i] - '0');
            res.insert(0, std::to_string((cur + retenue) % base));
            retenue = (cur + retenue) / base;
        }
        res.insert(0, std::to_string(retenue));
        return res;
    }
}