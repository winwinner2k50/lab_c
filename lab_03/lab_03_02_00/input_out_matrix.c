#include <stdio.h>
#include "helper.h"

int input_matrix(int a[][LEN], int n, int m)
{
    int res = OK;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                res = ERROR_INPUT_MATRIX;
    
    return res;
}

void out_matrix(int a[][LEN], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
         for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
