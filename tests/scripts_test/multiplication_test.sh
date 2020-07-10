#!/bin/bash

cmp_results "simple multiplication" "1*1"
cmp_results "medium multiplication" "1*2*3"
cmp_results "long multiplication" "1*2*3*4*5*6"
cmp_results "spaced multiplication" "1  *   1  *1 "
cmp_results "spaced multiplication" "     1 *1*1"
cmp_results "hard multiplication" "1107*2222*12"
cmp_results "hard multiplication" "101010*2*3*4"
cmp_results "hard multiplication" "4*23*3*23222"
cmp_results "hard multiplication" "1 * 222 *1 *2222"
cmp_results "hard multiplication" "999*999"
