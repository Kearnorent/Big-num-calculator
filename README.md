### This is a calculator for very large numbers

    Supporting '+', '-', '*', '/', '^', '%' operations.
 
### How to build the project

    mkdir build && cd build && cmake .. && make -j10
    
### How to run the project (Usage)

    Interactive Mode,
    ./calc
    ./calc -i
    
    Else, 
    ./calc "1 + 1 / 2 * 3 + (2 + 2) - 2"
    
    [Verbose Mode]
    ./calc -v "1 + 1 + 2"
