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
        std::cout << std::endl;
        for (int i = count; i < space; i++)
            std::cout << " ";
        std::cout << root->get_token().get_value() << std::endl;

        // Left child recursive call
        pretty_print_ast(root->left, space, count);
    }
}