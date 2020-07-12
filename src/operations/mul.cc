#include "operations.hh"

namespace operations
{
    std::string add(std::string n1, std::string n2);
    std::string subtract(std::string n1, std::string n2);

    std::string multiplication(std::string n1, std::string n2)
    {
        size_t length = std::max(n1.size(), n2.size());
        if (length == 1)
            return std::to_string((n1[0] - '0') * (n2[0] - '0'));
        while (n1.size() < length)
            n1.insert(0, "0");
        while (n2.size() < length)
            n2.insert(0, "0");

        std::string lhs0 = n1.substr(0, length / 2);
        std::string lhs1 = n1.substr(length / 2, length - length / 2);
        std::string rhs0 = n2.substr(0, length / 2);
        std::string rhs1 = n2.substr(length / 2, length - length / 2);

        std::string p0 = multiplication(lhs0, rhs0);
        std::string p1 = multiplication(lhs1, rhs1);
        std::string p2 = multiplication(add(lhs0, lhs1), add(rhs0, rhs1));
        std::string p3 = subtract(p2, add(p0, p1));

        for (size_t i = 0; i < 2 * (length - length / 2); i++)
            p0.append("0");
        for (size_t i = 0; i < length - length / 2; i++)
            p3.append("0");

        std::string result = add(add(p0, p1), p3);
        return result;
    }

    std::string add(std::string n1, std::string n2)
    {
        size_t length = std::max(n1.size(), n2.size());
        int carry = 0;
        int sum_col;
        std::string result;
        // pad the shorter string with zeros
        while (n1.size() < length)
            n1.insert(0, "0");
        while (n2.size() < length)
            n2.insert(0, "0");
        // build result string from right to left
        for (int i = length - 1; i >= 0; i--) {
            sum_col = (n1[i] - '0') + (n2[i] - '0') + carry;
            carry = sum_col / base;
            result.insert(0, std::to_string(sum_col % base));
        }
        if (carry)
            result.insert(0, std::to_string(carry));

        return result;
    }

    std::string subtract(std::string n1, std::string n2)
    {
        size_t length = std::max(n1.size(), n2.size());
        while (n1.size() < length)
            n1.insert(0, "0");
        while (n2.size() < length)
            n2.insert(0, "0");
        return subtraction(n1, n2);
    }
}