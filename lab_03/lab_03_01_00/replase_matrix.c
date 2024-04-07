#include "helper.h"

void replase_matrix(int a[][LEN], int n, int m)
{
    int column_pos;
    for (int j = 0; j < m; j++)
    {
        column_pos = 1;
        for(int i = 1; i < n; i++)
            if (a[i - 1][j] <= a[i][j])
                column_pos = 0;
               
        for (int i = 0; i < n; i++)
            a[i][j] = column_pos;
    }
}
