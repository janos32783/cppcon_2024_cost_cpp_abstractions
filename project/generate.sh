#!/bin/bash

ROOT_DIR_NAME=hal

# cleanup
rm -rf hal

# create directory
tar xzvf hal.tar.gz -C .

python3 process_svd.py ../documents/STM32F0x0.svd