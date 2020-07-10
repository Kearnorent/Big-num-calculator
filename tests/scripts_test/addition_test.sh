#!/bin/bash

cmp_results "simple addition" "1+1"
cmp_results "medium addition" "1+2+3"
cmp_results "long addition" "1+2+3+4+5+6"
cmp_results "spaced addition" "1  +   1  +1 "
cmp_results "spaced addition" "     1 +1+1"