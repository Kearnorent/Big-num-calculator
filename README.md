### This is a calculator for very large numbers

    Supporting '+', '-', '*', '/', '^', '%' operations in multiple bases.
 
### How to build the project

    mkdir build && cd build && cmake .. && make -j10
    
### How to run the project

    Interactive Mode :
    ./calc
    ./calc -i
    
###

    Classic mode :
    ./calc "1 + 1 / 2 * 3 + (2 + 2) - 2"       [Regular calculation in base 10, if no base is given]
    ./calc -b 2 "1+1+1"
    ./calc --base 2 "1+1+1"                    [-b / --base -> sets the base of operands]
    
###
    
    Verbose Mode (prints cool stuff such as the AST of the given expression) :
    ./calc -v                                   [Verbose + interactive mode]
    ./calc -v "1 + 1 * 2 + 1 * 2 + 1 * 2"
