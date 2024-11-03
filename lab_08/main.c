#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "matrix.h"

int main(void)
{
    void **a = NULL;
    size_t n, m;
    
    printf("Введите n m\n");
    scanf("%zu%zu", &n, &m);

    printf("Введите матрицу\n");
    matrix_input(&a, n, m, sizeof(double), num_input_double);

    matrix_output(a, n, m, sizeof(double), num_output_double);

    matrix_clear(&a, n);
    return 0;
}