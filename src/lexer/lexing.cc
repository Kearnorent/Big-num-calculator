#include "lexing.hh"

namespace lexer
{
    bool cmp_and_set_states (char cur_char, std::string& cur_string, tok_type& state)
    {
        tok_type new_state = NONE;
        if (is_number(cur_char))
            new_state = NUMBER;
        else if (is_operator(cur_char))
            new_state = OPERATOR;
        else if (cur_char == '(')
            new_state = LEFT_PAR;
        else if (cur_char == ')')
            new_state = RIGHT_PAR;

        if (state == NONE)
        {
            state = new_state;
            cur_string += cur_char;
        }
        else
        {
            if (state == NUMBER and state == new_state)
                cur_string += cur_char;
            else
            {
                state = new_state;
                cur_string = cur_char;
                return true;
            }
        }
        return false;
    }

    std::vector<lexer::t_token> lex (const std::string& operation)
    {
        std::vector<lexer::t_token> tokens;
        size_t op_size = operation.size();
        tokens.reserve(op_size);
        std::string cur_string;
        size_t i = 0;
        tok_type state = NONE;
        while (i < op_size)
        {
            std::string cpy_string = cur_string;
            tok_type cpy_state = state;
            if (cmp_and_set_states(operation[i], cur_string, state))
                tokens.emplace_back(t_token(cpy_string, cpy_state));
            if (i == op_size - 1)
                tokens.emplace_back(t_token(cur_string, state));
            ++i;
        }
        return tokens;
    }

    void pretty_print_tokens (const std::vector<lexer::t_token>& tokens)
    {
        int i = 1;
        for (auto token : tokens)
        {
            std::cout << "[Token " << i << "] \'" << token.get_value() << "\'" << " " << tok_type_to_string(token.get_type()) << std::endl;
            ++i;
        }
    }
}