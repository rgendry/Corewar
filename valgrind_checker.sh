#!/bin/bash

ASM="./asm/asm"

for S_FILE in $( find ${1} -type f -name "*.s" ) ; do
(valgrind ${ASM} ${S_FILE})
done