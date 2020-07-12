#include <iostream>
#include <vector>

#include "lexer/lexing.hh"
#include "lexer/token.hh"
#include "parser/parsing.hh"
#include "parser/ast_visit.hh"
#include "parser/ast.hh"
#include "utils/input_error.hh"
#include "utils/string_op.hh"
#include "utils/options.hh"

/// 'base' Global variable
int base = 10;

int main (int argc, char *argv[])
{
    Options options(argc, argv);
    /// Input error handling
    std::string error_msg;
    if (argc > 3 or not is_valid_operation(options.operation.c_str(), error_msg))
    {
        std::cout << "[Input Error] " << error_msg << std::endl;
        return 1;
    }

    while (true)
    {
        std::string operation;
        if (options.interactive)
        {
            std::getline (std::cin, operation);
            if (operation == "q" or operation == "quit" or operation == "stop")
            {
                std::cout << "Quitting\n";
                break;
            }
        }
        else
        {
            /// The operation string
            operation = options.operation;
        }

        /// Remove useless characters (spaces, ...)
        remove_useless_characters(operation);

        /// Puts 0 before negative numbers to make it easier later on
        add_zeroes(operation);

        /// Lexing
        std::vector<lexer::t_token> tokens = lexer::lex(operation);
        /// AST Building
        std::shared_ptr<parser::t_ast> ast = parser::parse(tokens, error_msg);
        /// Parsing error
        if (not ast)
        {
            std::cout << "[Parsing Error] " << error_msg << std::endl;
            if (not options.interactive)
                return 1;
            else
                continue;
        }

        /// AST Visiting
        visiter::visit(ast);

        /// FIXME Logging to delete
        /*parser::pretty_print_ast(ast, 0, 10);
        lexer::pretty_print_tokens(tokens);
        std::cout << operation << std::endl;*/

        /// Final logging
        std::string result = ast->get_token().get_value();
        remove_zeroes(result);
        std::cout << "\033[1;36m" << "= " << result << "\033[0m" << std::endl;

        if (not options.interactive)
            break;
    }

    return 0;
}