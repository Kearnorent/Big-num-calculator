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
            if (tokens[i].get_type() == LEFT_PAR)
            {
                size_t shift = 1;
                std::vector<lexer::t_token> tokens_between_pars = get_tokens_between_pars(tokens, i + 1, shift);
                std::shared_ptr<t_ast> par_ast = parse(tokens_between_pars, error_msg);
                operand_stack.push_back(par_ast);
                i = shift;
                state = NUMBER;
                continue;
            }
            if (tokens[i].get_type() == RIGHT_PAR)
                continue;
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

            /// Update the state
            state = tokens[i].get_type();
        }

        int prio = 3;
        while (prio > 0)
        {
            if (prio == 3)
            {
                int i = operator_stack.size() - 1;
                while (i >= 0)
                {
                    if (operator_type_to_int(operator_stack[i]) == prio)
                    {
                        std::shared_ptr<t_ast> cur =
                                std::make_shared<t_ast>(lexer::t_token(operator_type_to_string(operator_stack[i]), OPERATOR));
                        cur->left = operand_stack[i];
                        cur->right = operand_stack[i + 1];
                        /// Erase outdated elements
                        operand_stack.erase(operand_stack.begin() + i);
                        operator_stack.erase(operator_stack.begin() + i);
                        ///
                        operand_stack[i] = cur;
                        i--;
                    }
                    else
                        i--;
                }
            }
            else
            {
                size_t i = 0;
                while (i < operator_stack.size())
                {
                    if (operator_type_to_int(operator_stack[i]) == prio)
                    {
                        std::shared_ptr<t_ast> cur =
                                std::make_shared<t_ast>(lexer::t_token(operator_type_to_string(operator_stack[i]), OPERATOR));
                        cur->left = operand_stack[i];
                        cur->right = operand_stack[i + 1];
                        /// Erase outdated elements
                        operand_stack.erase(operand_stack.begin() + i);
                        operator_stack.erase(operator_stack.begin() + i);
                        ///
                        operand_stack[i] = cur;
                    }
                    else
                        i++;
                }
            }
            prio--;
        }

        if (not operand_stack.empty())
            return operand_stack[0];
        return nullptr;
    }

    std::vector<lexer::t_token> get_tokens_between_pars(std::vector<lexer::t_token>& tokens, size_t ind, size_t& shift)
    {
        int count_op = 1;
        int count_cl = 0;
        size_t i = ind;
        std::vector<lexer::t_token> res;
        while (i < tokens.size())
        {
            if (tokens[i].get_type() == LEFT_PAR)
                count_op += 1;
            else if (tokens[i].get_type() == RIGHT_PAR)
                count_cl += 1;
            if (count_cl == count_op)
                break;
            res.push_back(tokens[i]);
            i++;
        }
        shift = i;
        return res;
    }

}