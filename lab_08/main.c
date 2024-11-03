#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "matrix.h"

int main(void)
{
    char **lins;
    size_t n, m;
    
    printf("Введите n m\n");
    scanf("%zu%zu", &n, &m);

    printf("Введите матрицу\n");
    matrix_input(&lins, n, m, sizeof(double), num_input_double);
    
    matrix_output(lins, n, m, sizeof(double), num_output_double);

    matrix_clear(&lins, n);
    return 0;
}