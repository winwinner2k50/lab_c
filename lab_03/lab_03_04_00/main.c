#include <stdio.h>
#include "helper.h"

int main(void)
{
    int a[LEN][LEN];
    int n;
    int max;

    printf("Введите размер квадратичной матрицы\n");

    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Ошибка ввода размера матрицы\n");
        return ERROR_INPUT;
    }

    printf("Введите матрицу\n");

    if(input_matrix(a, n) == ERROR_INPUT_MATRIX)
    {
        printf("Ошибка ввода матрицы\n");
        return ERROR_INPUT_MATRIX;
    }
    
    if(try_find_maxpos_num(a, n, &max) == OK)
        printf("максимальное число: %d\n", max);
    else
    {
        printf("Число подходящие под условие не найдено\n");
        return ERROR_NOT_POS;
    }

    return OK;
}