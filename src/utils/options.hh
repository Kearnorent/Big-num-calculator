#pragma once

#include <cstring>
#include <string>
#include <iostream>

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
    int base = 10;
};