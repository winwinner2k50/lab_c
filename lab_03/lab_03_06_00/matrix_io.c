#include <stdio.h>
#include "matrix_io.h"
/*
int input_arr(int a[], size_t n)
{
    int res = 0;
    for (size_t i = 0; i < n; i++)
        if (scanf("%d", &a[i]) != 1)
            res = 1;

    return res;
}
*/
void out_matrix(int a[][LEN], size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
         for (size_t j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int gen_matrix(int a[][LEN], size_t n, size_t m)
{
    size_t element = 1;
    int first_str = 0;
    int vector = 1;
    for (size_t j = 0; j < m; j++)
    {
        for (size_t i = first_str; i < n; i+=vector)
        {
            a[i][j] = element;
            element++;
        }
        if (vector == 1)
        {
            first_str = n - 1;
            vector = -1;
        }
        else
        {
            first_str = 0;
            vector = 1;
        }    
    }

    return 0;
}

