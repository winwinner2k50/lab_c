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

void zero_in_arr(int a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        a[i] = 0;
}

void paste_hundred(int a[][LEN], size_t *n, size_t m, size_t pos_past)
{
    (*n)++;
    for (size_t i = (*n) - 1; i > pos_past; i--)
    {
        for (size_t j = 0; j < m; j++)
            a[i][j] = a[i - 1][j];
    }
    for (size_t j = 0; j < m; j++)
        a[pos_past][j] = 100;
}

void find_paste_pos_str(int a[][LEN], size_t *n, size_t m)
{
    int figure_first[LEN_FIGURE];
    int figure_last[LEN_FIGURE];
    int res;
    for (size_t i = 0; i < *n; i++)
    {
        zero_in_arr(figure_first, LEN_FIGURE);
        zero_in_arr(figure_last, LEN_FIGURE);
        res = 1;
        for (size_t j = 0; j < m; j++)
        {
            figure_first[find_figure_first(a[i][j])]++;
            figure_last[find_figure_last(a[i][j])]++;
        }
        
        for (size_t j = 0; j < LEN_FIGURE; j++)
        {
           // printf("%d) %d %d\n", j, figure_first[j], figure_last[j]);
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
