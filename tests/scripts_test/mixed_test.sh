#!/bin/bash

cmp_results "simple mixed" "1+1-2"
cmp_results "simple mixed" "1+1+-2"
cmp_results "simple mixed" "-2+77"
cmp_results "medium mixed" "1+2+3^2-2+2-100"
cmp_results "long mixed" "1+2*3+4/5+6%2-2+1*2%2^2/2+1/2"
cmp_results "spaced mixed" "8  / 3 +1 - 1 * 2"
cmp_results "spaced mixed" "     2 +10-100*100"
cmp_results "hard mixed" "1+2*3+4/5+6%2-2+1*2%2/2+1/2"
cmp_results "hard mixed" "1+22222*3+4/4325+6%22222-2+1*2%212456/218917+118751/22928226"
cmp_results "hard mixed" "2+2*3^2+2-4/2+1+2-9/22%8+10-10/2+2*44"
cmp_results "hard mixed" "2^8+22221^2*3+2987-45678/22213+14232+2322-9/2222%834+1330-12130/4452+2*42324"
cmp_results "hard mixed" "12343981/1213452+22221*3+2987-45678/22112113+14233452+2322987-1219/222223453%8342+133120-1212130/12435452+2*42376524"