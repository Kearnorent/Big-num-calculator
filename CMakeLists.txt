# SETUP
cmake_minimum_required(VERSION 3.12)
project(Chess)

# BUILD OPTIONS
set(CMAKE_CXX_STANDARD 17)

include_directories(src/)

#List of source files
set(SRC_FILES
        # Main
        src/main.cc

        # Lexer files
        src/lexer/lexing.cc
        src/lexer/token.cc
        src/lexer/token_type.cc

        # Parser files
        src/parser/parsing.cc
        src/parser/ast_visit.cc
        src/parser/ast.cc
        src/parser/operator_type.cc

        # Operations files
        src/operations/add.cc
        src/operations/sub.cc
        src/operations/mul.cc
        src/operations/div.cc
        src/operations/mod.cc
        src/operations/pow.cc

        # Utils files
        src/utils/input_error.cc
        src/utils/string_op.cc
        src/utils/options.cc
    )

# Compilation flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic -std=c++17")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Ofast -march=native")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g3")

add_executable(calc ${SRC_FILES})

# To run the testsuite
add_custom_target(check COMMAND cd ../tests && ./suite.sh && cd - > /dev/null)
add_custom_target(tests COMMAND cd ../tests && ./suite.sh && cd - > /dev/null)
add_custom_target(test COMMAND cd ../tests && ./suite.sh && cd - > /dev/null)