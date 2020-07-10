#include <memory>

#include "parsing.hh"

namespace parser
{
    std::shared_ptr<t_ast> parse (std::vector<lexer::t_token>& tokens, std::string& error_msg)
    {
        std::vector<operator_type> operator_stack;
        std::vector<std::shared_ptr<t_ast>> operand_stack;
        size_t len_tokens = tokens.size();
        tok_type state = NONE;
        for (size_t i = 0; i < len_tokens; ++i)
        {
            /// Parsing error cases
            if (i == len_tokens - 1 and tokens[i].get_type() != NUMBER)
            {
                error_msg = "Expected a number as last character but got \'" + tokens[i].get_value() + "\'.";
                return nullptr;
            }
            if (state == NUMBER and tokens[i].get_type() != OPERATOR)
            {
                error_msg = "Expected an operator after \'" + tokens[i - 1].get_value() + "\' but got \'" + tokens[i].get_value() + "\'.";
                return nullptr;
            }
            /// Handle '(' and ')' cases later
            else if (state == OPERATOR and tokens[i].get_type() != NUMBER)
            {
                error_msg = "Expected a number after \'" + tokens[i - 1].get_value() + "\' but got \'" + tokens[i].get_value() + "\'.";
                return nullptr;
            }
            /// Update the stacks
            if (tokens[i].get_type() == NUMBER)
                operand_stack.push_back(std::make_shared<t_ast>(tokens[i]));
            else if (tokens[i].get_type() == OPERATOR)
                operator_stack.push_back(guess_operator_type(tokens[i].get_value()));

            /// Update the stacks after added elements to them
            update_the_stacks(operator_stack, operand_stack);

            /// Update the state
            state = tokens[i].get_type();
        }

        /// Loop until the operator stack is empty
        while (not operator_stack.empty())
        {
            update_the_stacks(operator_stack, operand_stack);
            if (operator_stack.size() == 1 and operand_stack.size() == 2)
            {
                std::shared_ptr<t_ast> cur = std::make_shared<t_ast>(lexer::t_token(operator_type_to_string(operator_stack[0]), OPERATOR));
                cur->left = operand_stack[0];
                cur->right = operand_stack[1];
                operand_stack.clear();
                operand_stack.push_back(cur);
                operator_stack.clear();
            }
        }

        if (not operand_stack.empty())
            return operand_stack[0];
        return nullptr;
    }

    void update_the_stacks (std::vector<operator_type>& operator_stack, std::vector<std::shared_ptr<t_ast>>& operand_stack)
    {
        if (not operator_stack.empty())
        {
            operator_type top_operator_elm = operator_stack[operator_stack.size() - 1];
            if (is_operator_max_prio(top_operator_elm) and operator_stack.size() + 1 == operand_stack.size())
            {
                std::shared_ptr<t_ast> cur = std::make_shared<t_ast>(lexer::t_token(operator_type_to_string(top_operator_elm), OPERATOR));
                cur->left = operand_stack[operand_stack.size() - 2];
                cur->right = operand_stack[operand_stack.size() - 1];
                /// Erase outdated elements
                operand_stack.erase(operand_stack.end() - 1);
                operand_stack.erase(operand_stack.end() - 1);
                operator_stack.erase(operator_stack.end() - 1);
                /// Update operand stack
                operand_stack.push_back(cur);
            }
            else if (operator_stack.size() > 1
            and compare_priorities(operator_stack[0], operator_stack[1]) >= 0)
            {
                std::shared_ptr<t_ast> cur = std::make_shared<t_ast>(lexer::t_token(operator_type_to_string(operator_stack[0]), OPERATOR));
                cur->left = operand_stack[0];
                cur->right = operand_stack[1];
                /// Erase outdated elements
                operand_stack.erase(operand_stack.begin());
                operator_stack.erase(operator_stack.begin());
                /// Update operand stack
                operand_stack[0] = cur;
            }
        }
    }

    bool is_operator_max_prio (const operator_type& type)
    {
        /// FIXME
        return type == MULT or type == DIV or type == MOD;
    }

    int compare_priorities (operator_type type1, operator_type type2)
    {
        return operator_type_to_int(type1) - operator_type_to_int(type2);
    }
}