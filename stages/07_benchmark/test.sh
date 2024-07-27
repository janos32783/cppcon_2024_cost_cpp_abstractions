#!/bin/bash

export TIMEFORMAT=%3R

CSV_FILE_C_01="01_data_c.csv"
CSV_FILE_CPP_01="01_data_cpp.csv"
CSV_FILE_02_basic="02_basic_data.csv"
CSV_FILE_02_template="02_template_data.csv"
CSV_FILE_03="03_data.csv"

echo "num_funcs,comp_t" > $CSV_FILE_C_01
echo "num_funcs,comp_t" > $CSV_FILE_CPP_01
echo "num_class,comp_t" > $CSV_FILE_02_basic
echo "num_class,comp_t" > $CSV_FILE_02_template
echo "num_class,comp_t" > $CSV_FILE_03

EPOCHS=1000
for i in $( eval echo {0..$EPOCHS} ); do
    python3 01_generate.py $((1 + $i / 5))
    python3 02_generate.py $((1 + $i / 5))
    
    C_COMPILE_TIME=`(time make target_01_c) 2>&1 >/dev/null`
    echo $C_COMPILE_TIME >> $CSV_FILE_C_01
    make clean
    C_COMPILE_TIME=`(time make target_01_cpp) 2>&1 >/dev/null`
    echo $C_COMPILE_TIME >> $CSV_FILE_CPP_01
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
