#include <iostream>

#include "utils/input_error.hh"
#include "utils/string_op.hh"

int main (int argc, char *argv[])
{
    // Input error handling
    std::string error_msg = "";
    if (argc != 2 or not is_valid_operation(argv[1], error_msg))
    {
        std::cout << "[Input Error] " << error_msg << std::endl;
        return 1;
    }
    // The operation
    std::string operation = argv[1];

    // Remove useless characters (spaces, ...)
    remove_useless_characters(operation);

    // FIXME To delete
    std::cout << operation << std::endl;

    return 0;
}