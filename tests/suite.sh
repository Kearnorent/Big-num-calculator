#!/bin/bash

# Testsuite script

# Colors
green='\033[1;32m'
blue='\033[0;34m'
purple='\033[0;35m'
cyan='\033[1;36m'
gray='\033[0;37m'
red='\033[1;31m'
reset='\033[0m'

# Verify that we are in the right folder (tests/)
dir="$(basename $PWD)"
if [ $dir != "tests" ]; then
    echo -e "$cyan""You need to be in the $red'Spider/tests/'$cyan" \
        "directory to launch the testsuite. $reset"
    exit 1
fi

# Logging
echo -e "$cyan""Current directory:" $PWD

# Counters initialization
total_tests=0
total_passed=0

is_argument ()
{
    arg=$1
    nb=$2
    if [ $nb -eq 0 ]; then
        return 0
    fi
    temp=$3
    for elm in $arg; do
        if [ "$elm" == "$temp" ]; then
            return 0
        fi
    done
    return 1
}

cmp_results ()
{
    total_tests=$((total_tests + 1))
    test_name=$1
    op=$2
    mine=$(./../build/calc "$op")
    op2=$(echo "$op" | sed -r 's/[\^]+/**/g')
    expected=$(($op2))
    if [[ "$mine" == *"$expected"* ]]; then
        echo -e "$green[OK]""$cyan""[$test_name] "
        tests_passed=$((tests_passed + 1))
    else
        echo -e "$red[KO]""$cyan""[$test_name] " \
        "$gray""Expected: '$expected'"
    fi
}

# Addition tests
if is_argument "$*" "$#" "add"; then
    . scripts_test/addition_test.sh
fi
# Subtraction tests
if is_argument "$*" "$#" "sub"; then
    . scripts_test/subtraction_test.sh
fi
# Multiplication tests
if is_argument "$*" "$#" "mult"; then
    . scripts_test/multiplication_test.sh
fi
# Division tests
if is_argument "$*" "$#" "div"; then
    . scripts_test/division_test.sh
fi
# Modulo tests
if is_argument "$*" "$#" "mod"; then
    . scripts_test/mod_test.sh
fi
# Power tests
if is_argument "$*" "$#" "pow"; then
    . scripts_test/pow_test.sh
fi
# Hard/Mixed tests
if is_argument "$*" "$#" "mixed"; then
    . scripts_test/mixed_test.sh
fi

# Logging
echo -e "$green\n[$tests_passed/$total_tests tests passed!]"

# Reset print color
echo -ne $reset

exit 0