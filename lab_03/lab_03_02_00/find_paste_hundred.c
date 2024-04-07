#include <stdio.h>
#include "helper.h"


int find_figure_first(int a)
{
    int res;
    while (a > 0)
    {
        res = a % 10;
        a /= 10;
    }
    return res;
}

int find_figure_last(int a)
{
    return a % 10;
}

void zero_in_arr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = 0;
}

void paste_hundred(int a[][LEN], int *n, int m, int pos_past)
{
    (*n)++;
    for (int i = (*n) - 1; i > pos_past; i--)
    {
        for (int j = 0; j < m; j++)
            a[i][j] = a[i - 1][j];
    }
    for (int j = 0; j < m; j++)
        a[pos_past][j] = 100;
}

void find_paste_pos_str(int a[][LEN], int *n, int m)
{
    int figure_first[LEN_FIGURE];
    int figure_last[LEN_FIGURE];
    int res;
    for (int i = 0; i < *n; i++)
    {
        zero_in_arr(figure_first, LEN_FIGURE);
        zero_in_arr(figure_last, LEN_FIGURE);
        res = 1;
        for (int j = 0; j < m; j++)
        {
            figure_first[find_figure_first(a[i][j])]++;
            figure_last[find_figure_last(a[i][j])]++;
        }
        
        for (int j = 0; j < LEN_FIGURE; j++)
        {
            printf("%d) %d %d\n", j, figure_first[j], figure_last[j]);
            if (figure_first[j] != figure_last[j])
                res = 0;
        }
            
        if (res == 1)
        {
            paste_hundred(a, &(*n), m, i+1);
            i++;
        }
            
    }
}
