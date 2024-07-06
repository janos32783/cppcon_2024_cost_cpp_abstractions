#!/bin/bash

taskset -c 2 ./test.sh 1 &
taskset -c 3 ./test.sh 20 &
taskset -c 4 ./test.sh 50 &
taskset -c 5 ./test.sh 100 &
