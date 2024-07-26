#!/bin/bash

export TIMEFORMAT=%3R

CSV_FILE_01="01_data.csv"
CSV_FILE_02_basic="02_basic_data.csv"
CSV_FILE_02_template="02_template_data.csv"
CSV_FILE_03="03_data.csv"

echo "num_funcs,comp_t" > $CSV_FILE_01
echo "num_regs,comp_t" > $CSV_FILE_02_basic
echo "num_regs,comp_t" > $CSV_FILE_02_template
echo "num_regs,comp_t" > $CSV_FILE_03

EPOCHS=10000
for i in $( eval echo {0..$EPOCHS} ); do
    python3 01_generate.py
    python3 02_generate.py
    
    C_COMPILE_TIME=`(time make target_01) 2>&1 >/dev/null`
    echo $C_COMPILE_TIME >> $CSV_FILE_01
    make clean
    C_COMPILE_TIME=`(time make target_02_basic) 2>&1 >/dev/null`
    echo $C_COMPILE_TIME >> $CSV_FILE_02_basic
    make clean
    C_COMPILE_TIME=`(time make target_02_template) 2>&1 >/dev/null`
    echo $C_COMPILE_TIME >> $CSV_FILE_02_template
    make clean
    C_COMPILE_TIME=`(time make target_03) 2>&1 >/dev/null`
    echo $C_COMPILE_TIME >> $CSV_FILE_03
    make clean

    PROC=$(($i / ($EPOCHS / 100)))
    echo -ne "$PROC%"\\r
done
