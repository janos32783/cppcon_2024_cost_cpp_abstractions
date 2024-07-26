#!/bin/bash

export TIMEFORMAT=%3R

CSV_FILE="data.csv"

echo "num_funcs,num_calls,comp_t" > $CSV_FILE

for i in {1..100}; do
    python3 generate.py
    C_COMPILE_TIME=`(time make) 2>&1 >/dev/null`
    echo $C_COMPILE_TIME >> $CSV_FILE
done
