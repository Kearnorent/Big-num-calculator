#include "operations.hh"

namespace operations
{
    std::string modulo(std::string n1, std::string n2)
    {
        std::string div = visiter::calculate("/", n1, n2);
        std::string mul = visiter::calculate("*", div, n2);
        return visiter::calculate("-", n1, mul);
    }
}