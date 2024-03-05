#!/bin/bash
number_of_lab=$1
number_of_zada=$2
m=$3
q=lab_"$1"_"$2"_"$m" 
echo ./"$q"/main.c
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -o ./"$q"/main.exe ./"$q"/main.c -lm 
if [ $? -eq 0 ]
then
./"$q"/main.exe
fi