#include <stdio.h>
#include "matrix_io.h"

int main(void)
{
    int a[LEN][LEN];
   // int arr_for_matrix[LEN*LEN];
    size_t n, m;

    printf("Введите количество строк и столбцов в матрице\n");

    if (scanf("%zu%zu", &n, &m) != 2 || n <= 0 || m <= 0)
    {
        printf("Ошибка ввода размера матрицы\n");
        return ERROR_INPUT;
    }
    /*
    printf("Введите массив элементов матрицы\n");

    if(input_arr(arr_for_matrix, n * m))
    {
        printf("Ошибка ввода массива\n");
        return ERROR_INPUT_ARR;
    }
    */
    gen_matrix(a, n, m);

    printf("Изменённая матрица\n");
    out_matrix(a, n, m);

    return OK;
}