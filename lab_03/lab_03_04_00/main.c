#include <stdio.h>
#include "matrix_io.h"

int main(void)
{
    int a[LEN][LEN];
    size_t n, m;
    int min;

    printf("Введите размер квадратичной матрицы\n");

    if (scanf("%zu%zu", &n, &m) != 2 || n <= 0 || m != n)
    {
        printf("Ошибка ввода размера матрицы\n");
        return ERROR_INPUT;
    }

    printf("Введите матрицу\n");

    if(input_matrix(a, n, m) == 1)
    {
        printf("Ошибка ввода матрицы\n");
        return ERROR_INPUT_MATRIX;
    }
    
    if(try_find_min_pos(a, &min, n, m) == OK)
        printf("минимальное число: %d\n", min);
    else
    {
        printf("Число подходящие под условие не найдено\n");
        return ERROR_NOT_POS;
    }

    return OK;
}