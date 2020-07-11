#!/bin/bash

cmp_results "simple subtraction" "1-1"
cmp_results "medium subtraction" "1-2-3"
cmp_results "medium subtraction" "1121-21212-3121"
cmp_results "medium subtraction" "9876-21991-39887-1233454"
cmp_results "medium subtraction" "98761-1234-987-9876-987-123-1234"
cmp_results "long subtraction" "1-2-3-4-5-6"
cmp_results "long subtraction" "1-2-3-4-5-6-1982-981786-12234-827265-1928327"
cmp_results "long subtraction" "1918-176253-22-29827-14267-2983478-1234-987654"
cmp_results "spaced subtraction" "1  -   1  -1 "
cmp_results "spaced subtraction" "     1 -1-1"