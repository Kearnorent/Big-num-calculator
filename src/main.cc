#include <iostream>
#include <vector>

#include "lexer/lexing.hh"
#include "lexer/token.hh"
#include "parser/parsing.hh"
#include "parser/ast_visit.hh"
#include "parser/ast.hh"
#include "utils/input_error.hh"
#include "utils/string_op.hh"

int main (int argc, char *argv[])
{
    /// Input error handling
    std::string error_msg;
    if (argc != 2 or not is_valid_operation(argv[1], error_msg))
    {
        std::cout << "[Input Error] " << error_msg << std::endl;
        return 1;
    }

    /// The operation string
    std::string operation = argv[1];

    /// Remove useless characters (spaces, ...)
    remove_useless_characters(operation);

    /// Lexing
    std::vector<lexer::t_token> tokens = lexer::lex(operation);
    /// AST Building
    std::shared_ptr<parser::t_ast> ast = parser::parse(tokens, error_msg);
    /// Parsing error
    if (not ast)
    {
        std::cout << "[Parsing Error] " << error_msg << std::endl;
        return 1;
    }

    /// AST Visiting
    visiter::visit(ast);

    /// FIXME Logging to delete
    //parser::pretty_print_ast(ast, 0, 10);
    //std::cout << std::endl;
    //lexer::pretty_print_tokens(tokens);
    //std::cout << std::endl << operation << std::endl;

    /// Final logging
    std::cout << "The result is : " << ast->get_token().get_value() << std::endl;

    return 0;
}