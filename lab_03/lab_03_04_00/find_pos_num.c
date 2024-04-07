#include <stdio.h>
#include "helper.h"

int try_find_maxpos_num(int a[][LEN], int n, int *max)
{
    int res = ERROR_NOT_POS;
    for (int i = 0; i < n; i++)
    {
         for (int j = 0; j < n; j++)
         {
             if (j < i && a[i][j] % 2 != 0 && *max < a[i][j])
             {
                *max = a[i][j];
                res = OK;
             }
                
         }            
    }
    return res;
}