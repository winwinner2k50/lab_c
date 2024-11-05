#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "matrix_input_output.h"
#include "matirx_operation.h"

int main(void)
{
    void **a = NULL;
    size_t n, m;

    void **b = NULL;
    size_t p, q;
    
    printf("Введите n m\n");
    scanf("%zu%zu", &n, &m);

    printf("Введите матрицу\n");
    matrix_input(&a, n, m, sizeof(double), num_input_double);

    printf("Введите p q\n");
    scanf("%zu%zu", &p, &q);

    printf("Введите матрицу\n");
    matrix_input(&b, p, q, sizeof(double), num_input_double);

    matrix_output(a, n, m, sizeof(double), num_output_double);
    printf("\n");
    matrix_output(b, p, q, sizeof(double), num_output_double);

    printf("\n-------------\n");

    matrix_square_with_dell(&a, &n, &m, sizeof(double), num_min_double);

    matrix_square_with_dell(&b, &p, &q, sizeof(double), num_min_double);

    matrix_output(a, n, m, sizeof(double), num_output_double);
    printf("\n");
    matrix_output(b, p, q, sizeof(double), num_output_double);

    printf("\n-------------\n");

    if (p != n)
    {
        if (n < p)
            matrix_magnification(&a, &n, &m, sizeof(double), p - n, matrix_add_col, matrix_add_str_double);
        else
            matrix_magnification(&b, &p, &q, sizeof(double), n - p, matrix_add_col, matrix_add_str_double);
    }

    // matrixes_equal_size(&a, &n, &m, &b, &p, &q, sizeof(double), matrix_add_col, matrix_add_str_double);
    
    matrix_output(a, n, m, sizeof(double), num_output_double);
    printf("\n");
    matrix_output(b, p, q, sizeof(double), num_output_double);
    matrix_clear(&a, n);
    matrix_clear(&b, p);
    return 0;
}