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

void replace_ell_matrix(int a[][LEN], size_t n, size_t m)
{
    
    for (size_t j = 0; j < m; j++)
    {
        size_t column_pos = 1;
        for(size_t i = 1; i < n; i++)
            if (a[i - 1][j] <= a[i][j])
                column_pos = 0;
               
        for (size_t i = 0; i < n; i++)
            a[i][j] = column_pos;
    }
}


