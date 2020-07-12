#include "ast.hh"

namespace parser
{
    t_ast::t_ast(const lexer::t_token& tok)
        :   left(nullptr),
            right(nullptr),
            token(tok)
    {
    }

    void pretty_print_ast(std::shared_ptr<t_ast> root, int space, int count)
    {
        if (root == nullptr)
            return;

        // Increase distance between levels
        space += count;

        // Right child recursive call
        pretty_print_ast(root->right, space, count);

        // Print current node
        //std::cout << std::endl;
        for (int i = count; i < space; i++)
            std::cout << " ";
        if (root->get_token().get_type() == OPERATOR)
            std::cout << "\033[1;30m" << root->get_token().get_value() << "\033[0m" << std::endl;
        else
            std::cout << "\033[1;33m" << root->get_token().get_value() << "\033[0m" << std::endl;

        // Left child recursive call
        pretty_print_ast(root->left, space, count);
    }

    int get_tree_depth (std::shared_ptr<t_ast> root, int depth)
    {
        if (root == nullptr)
            return depth;
        else
            return std::max(get_tree_depth(root->left, depth + 1), get_tree_depth(root->right, depth + 1));
    }

    void get_elems_at_depth (std::shared_ptr<t_ast> root, int depth,
            std::vector<std::vector<lexer::t_token>>& levels, int max_depth)
    {
        if (root == nullptr)
            return;
        else
        {
            levels[depth].push_back(root->get_token());
            if (depth + 1 < max_depth)
            {
                if (root->left == nullptr)
                    levels[depth + 1].push_back(lexer::t_token("0", NONE));
                if (root->right == nullptr)
                    levels[depth + 1].push_back(lexer::t_token("0", NONE));
            }
            get_elems_at_depth(root->left, depth + 1, levels, max_depth);
            get_elems_at_depth(root->right, depth + 1, levels, max_depth);
        }
    }

    void pretty_print_ast2(std::shared_ptr<t_ast> root, size_t line_len)
    {
        std::cout << "\033[1;33m" << "[The AST looks like]" << "\033[0m" << std::endl;
        int depth = get_tree_depth(root, 0);
        std::vector<std::vector<lexer::t_token>> levels(depth);
        /// Fills the vector
        get_elems_at_depth(root, 0, levels, depth);
        for (int i = 0; i < depth; ++i)
        {
            int c = 0;
            for (auto e : levels[i])
            {
                if (c == 0)
                {
                    for (size_t j = 0; j < line_len / std::pow(2, i); ++j)
                        std::cout << " ";
                }
                else
                {
                    for (int k = 0; k <= 1; ++k)
                        for (size_t j = 0; j < line_len / std::pow(2, i); ++j)
                            std::cout << " ";
                }
                if (e.get_type() != NONE)
                {
                    if (e.get_type() == OPERATOR)
                        std::cout << "\033[1;30m" << "[" << e.get_value() << "]" << "\033[0m";
                    else
                        std::cout << "\033[1;33m" << e.get_value() << "\033[0m";
                }
                c++;
            }
            std::cout << "\n\n";
        }
    }
}