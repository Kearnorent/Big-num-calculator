#pragma once

#include <cstring>
#include <string>

class Options
{
public:
    Options(int argc, char *argv[]);

    std::string operation;
    bool interactive = false;
    bool verbose = false;
};