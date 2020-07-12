#include "options.hh"

Options::Options(int argc, char *argv[])
{
    if (argc == 1)
        interactive = true;
    for (int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "-i") == 0)
            interactive = true;
        else if (strcmp(argv[i], "-v") == 0)
            verbose = true;
        else if (i + 1 < argc and (strcmp(argv[i], "-b") == 0 or strcmp(argv[i], "--base") == 0))
        {
            base = std::stoi(argv[i + 1]);
            i += 1;
        }
        else
            operation = argv[i];
    }
    if (operation == "")
        interactive = true;
}