#!/bin/bash

cmp_results "simple modulo" "1%1"
cmp_results "medium modulo" "1%2%3"
cmp_results "long modulo" "1%2%3%4%5%6"
cmp_results "spaced modulo" "1  %   1  %1 "
cmp_results "spaced modulo" "     1 %1%1"
cmp_results "hard modulo" "1107%2222%12"
cmp_results "hard modulo" "101010%2%3%4"
cmp_results "hard modulo" "4%23%3%23222"
cmp_results "hard modulo" "1 % 222 %1 %2222"
cmp_results "hard modulo" "999%999"
