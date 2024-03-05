#!/bin/bash
echo "название лабы: "
read name_lab
mkdir $name_lab
cd $name_lab

echo "введите номер лабы (XX): "
read num_lab
echo "введите количество номеров в лабе:"
read kolvo_z

for ((i=1; i <= $kolvo_z; i++))
do
    echo "введите ваш вариант в задаче $i (XX):"
    read var_in_lab
    if [ "$i" -gt 9 ]
    then
        q=$i
    else
        q='0'$i
    fi
    mkdir "lab_""$num_lab""_""$q""_""$var_in_lab"
    cd "lab_""$num_lab""_""$q""_""$var_in_lab"

    touch main.c

    mkdir func_tests
    cd func_tests

    touch readme.md

    mkdir data

    cd data

    echo "Введите количество положительных тестов для задачи $i: "
    read kolvo1
    echo "Введите количество не положительных тестов для задачи $i: "
    read kolvo2
    for ((j=1; j <= $kolvo1; j++))
    do
        if [ "$j" -gt 9 ]
        then
            q=$j
        else
            q='0'$j
        fi
        touch "pos_""$q""_in.txt"
        touch "pos_""$q""_out.txt"
    done
    for ((j=1; j <= $kolvo2; j++))
    do
        if [ "$j" -gt 9 ]
        then
            q=$j
        else
            q='0'$j
        fi
        touch "neg_""$q""_in.txt"
        touch "neg_""$q""_out.txt"
    done
    cd ..
    cd ..
    cd ..
done
