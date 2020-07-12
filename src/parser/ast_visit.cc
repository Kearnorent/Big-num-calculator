#include "ast_visit.hh"

namespace visiter
{
    void visit (std::shared_ptr<parser::t_ast> ast)
    {
        while (ast->left != nullptr and ast->right != nullptr)
        {
            loop_through(ast);
        }
    }

    std::string calculate (const std::string& operation, std::string op1, std::string op2)
    {
        /// Add zeroes at the start of op1 or op2 to make them the same size
        int count = 0;
        std::string zeroes;
        if (op1.size() < op2.size())
        {
            while (op1.size() + count < op2.size())
            {
                count += 1;
                zeroes += '0';
            }
            if (op2[0] == '-')
                op1 = zeroes.substr(1) + op1;
            else
                op1 = zeroes + op1;
        }
        else if (op1.size() > op2.size())
        {
            while (op2.size() + count < op1.size())
            {
                count += 1;
                zeroes += '0';
            }
            if (op1[0] == '-')
                op2 = zeroes.substr(1) + op2;
            else
                op2 = zeroes + op2;
        }
        int num1 = std::stoi(op1);
        int num2 = std::stoi(op2);
        if (operation == "+")
            return operations::addition(op1, op2);
        else if (operation == "-")
            return operations::subtraction(op1, op2);
        else if (operation == "*")
            return operations::multiplication(op1, op2);
        else if (operation == "/")
            return std::to_string(num1 / num2);
            //return operations::division(op1, op2);
        else if (operation == "%")
            return std::to_string(num1 % num2);
            //return operations::modulo(op1, op2);
        else if (operation == "^")
            return std::to_string((int) std::pow(num1, num2));
            //return operations::power(op1, op2);
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