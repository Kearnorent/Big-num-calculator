#!/bin/bash

cmp_results "simple pow" "1^1"
cmp_results "medium pow" "1^2^3"
cmp_results "long pow" "1^2^3"
cmp_results "spaced pow" "1  ^   1  ^1 "
cmp_results "spaced pow" "     1 ^1^1"
cmp_results "hard pow" "5^2^3"
cmp_results "hard pow" "10^2^3"
cmp_results "hard pow" "4^2^3"
cmp_results "hard pow" "1 ^ 5 ^1 ^2"
cmp_results "hard pow" "999^3"
