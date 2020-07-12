#pragma once

#include <cstring>
#include <string>

class Options
{
public:
    /**
     * @param argc                      The number of program-given parameters
     * @param argv                      The program-given parameters
     */
    Options(int argc, char *argv[]);

    std::string operation;
    bool interactive = false;
    bool verbose = false;
};