#!/bin/bash

cmp_results "simple division" "1/1"
cmp_results "medium division" "1/2/3"
cmp_results "long division" "1/2/3/4/5/6"
cmp_results "spaced division" "1  /   1  /1 "
cmp_results "spaced division" "     1 /1/1"
cmp_results "hard division" "1107/2222/12"
cmp_results "hard division" "101010/2/3/4"
cmp_results "hard division" "4/23/3/23222"
cmp_results "hard division" "1 / 222 /1 /2222"
cmp_results "hard division" "999/999"
