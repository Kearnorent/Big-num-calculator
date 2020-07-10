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
        else
            operation = argv[i];
    }
}