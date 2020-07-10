#include "ast_visit.hh"

namespace visiter
{
    void visit (std::shared_ptr<parser::t_ast> ast)
    {
        while (ast->left != nullptr and ast->right != nullptr)
        {
            loop_through(ast);
            //parser::pretty_print_ast(ast, 0, 10);
        }
    }

    std::string calculate (const std::string& operation, const std::string& op1, const std::string& op2)
    {
        // FIXME for very large numbers

        int num1 = std::stoi(op1);
        int num2 = std::stoi(op2);
        if (operation == "+")
            return std::to_string(num1 + num2);
        else if (operation == "-")
            return std::to_string(num1 - num2);
        else if (operation == "*")
            return std::to_string(num1 * num2);
        else if (operation == "/")
            return std::to_string(num1 / num2);
        else if (operation == "%")
            return std::to_string(num1 % num2);
        // FIXME When I'll handle 'power' calculations.
        else if (operation == "^")
            return std::to_string(num1 / num2);
        return "";
    }

    void loop_through (std::shared_ptr<parser::t_ast> ast)
    {
        if (ast->get_token().get_type() == OPERATOR and ast->left->get_token().get_type() == NUMBER
        and ast->right->get_token().get_type() == NUMBER)
        {
            ast->set_token(lexer::t_token(calculate(ast->get_token().get_value(), ast->left->get_token().get_value(),
                                ast->right->get_token().get_value()), NUMBER));
            /// Clear
            ast->left = nullptr;
            ast->right = nullptr;
        }
        if (ast->left)
            loop_through(ast->left);
        if (ast->right)
            loop_through(ast->right);
    }
}