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

int try_find_min_pos(int a[][LEN], int *min, size_t n, size_t m)
{
    int res = ERROR_NOT_POS;
    for (size_t i = 0; i < n; i++)
    {
         for (size_t j = 0; j < m; j++)
         {
             if (j < i && a[i][j] % 2 != 0 && *min > a[i][j])
             {
                *min = a[i][j];
                res = OK;
             }
         }         
    }
    return res;
}