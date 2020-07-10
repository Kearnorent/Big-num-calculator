### Calculator for very large numbers

    Supporting '+', '-', '*', '/', '^', '%' operations.
 
### Build the project

    mkdir build && cd build && cmake .. && make -j10
    
### Usage

    Interactive Mode,
    ./calc
    ./calc -i
    
    Else, 
    ./calc "1 + 1 / 2 * 3 + (2 + 2) - 2"
    
    [Verbose Mode] FIXME
    ./calc -v "1 + 1 + 2"
