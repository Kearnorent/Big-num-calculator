#!/bin/bash

cmp_results "simple subtraction" "1-1"
cmp_results "medium subtraction" "1-2-3"
cmp_results "long subtraction" "1-2-3-4-5-6"
cmp_results "spaced subtraction" "1  -   1  -1 "
cmp_results "spaced subtraction" "     1 -1-1"