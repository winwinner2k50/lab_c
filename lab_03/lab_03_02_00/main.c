#include <stdio.h>
#include "matrix_io.h"

int main(void)
{
    int a[LEN*2][LEN];
    size_t n, m;

    printf("Введите количество строк и столбцов в матрице\n");
    
    if (scanf("%zu%zu", &n, &m) != 2 || n <= 0 || m <= 0)
    {
        printf("Ошибка ввода размера матрицы\n");
        return ERROR_INPUT;
    }

    printf("Введите матрицу\n");

    if(input_matrix(a, n, m) == ERROR_INPUT_MATRIX)
    {
        printf("Ошибка ввода матрицы\n");
        return ERROR_INPUT_MATRIX;
    }
    
    find_paste_pos_str(a, &n, m);

    printf("Изменённая матрица\n");
    out_matrix(a, n, m);

    return OK;
}