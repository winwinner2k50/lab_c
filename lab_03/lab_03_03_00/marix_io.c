#include <stdio.h>
#include "matrix_io.h"

int input_matrix(int a[][LEN], size_t n, size_t m)
{
    int res = OK;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                res = ERROR_INPUT_MATRIX;
    
    return res;
}

void out_matrix(int a[][LEN], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
         for (size_t j = 0; j < m; j++)
            printf("%d ", a[i][j]);

        printf("\n");
    }
}

void find_sum_str(int a[][LEN], int sum_str[], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
         for (size_t j = 0; j < m; j++)
         { 
            if (j == 0)
                sum_str[i] = 0;
            sum_str[i] += a[i][j];
         }  
            
    }
}

void arr_swap_el(int *a, int *b)
{
    int num_a = *a;
    *a = *b;
    *b = num_a;
}

void matrix_swap_str(int a[], int b[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        arr_swap_el(&a[i], &b[i]);
}

void sort_matrix_dy_arr(int a[][LEN], int sum_str[], size_t n, size_t m)
{
    for (size_t i = 1; i < n; i++)
    {
        for (size_t j = 0; j < n - i; j++)
            if (sum_str[j] > sum_str[j + 1])
            {
                arr_swap_el(&sum_str[j], &sum_str[j + 1]);
                matrix_swap_str(a[j], a[j + 1], m);
            }
    }
}

void sort_matrix_ascending_str(int a[][LEN], size_t n, size_t m)
{
    int sum_str[LEN];
    find_sum_str(a, sum_str, n, m);
    sort_matrix_dy_arr(a, sum_str, n, m);
}




