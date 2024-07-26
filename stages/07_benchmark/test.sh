#!/bin/bash

export TIMEFORMAT=%3R

CSV_FILE="data.csv"

echo "num_funcs,num_calls,comp_t" > $CSV_FILE

EPOCHS=10000
for i in $( eval echo {0..$EPOCHS} ); do
    python3 generate.py
    C_COMPILE_TIME=`(time make) 2>&1 >/dev/null`
    echo $C_COMPILE_TIME >> $CSV_FILE

    PROC=$(($i / ($EPOCHS / 100)))
    echo -ne "$PROC%"\\r
done
