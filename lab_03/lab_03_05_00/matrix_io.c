#include <stdio.h>
#include <math.h>
#include "matrix_io.h"
#include <stdlib.h>

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

int is_prime(int a)
{
    a = abs(a);
    if (a == 1)
        return 0;
    if (a == 2)
        return 1;
    if (a % 2 == 0)
        return 0;

    for (int i = 3; i < sqrt(a) + 1; i += 2)
        if (a % 3 == 0)
            return 0;

    return 1;
}

void arr_swap(int a[], size_t i, size_t j)
{
    int el = a[i];
    a[i] = a[j];
    a[j] = el;
}

void arr_revers(int a[], size_t n)
{
    for (size_t i = 0; i < n / 2; i++)
            arr_swap(a, i, n - i - 1);
}

void remove_el(int a[][LEN], int new_el[], size_t new_el_pos[][2], size_t new_el_count)
{
    for (size_t i = 0; i < new_el_count; i++)
        a[new_el_pos[i][0]][new_el_pos[i][1]] = new_el[i];
}
/*
void out_arr(int a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
*/
int find_remove_prime(int a[][LEN], size_t n, size_t m)
{
    int res = 0;
    int prime_el[LEN*LEN];
    size_t prime_el_pos[LEN][2];
    size_t prime_el_count = 0;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (is_prime(a[i][j]))
            {
                prime_el_count++;
                prime_el[prime_el_count - 1] = a[i][j];
                prime_el_pos[prime_el_count - 1][0] = i;
                prime_el_pos[prime_el_count - 1][1] = j;
            }
    if (prime_el_count != 0)
    {
        arr_revers(prime_el, prime_el_count);
        remove_el(a, prime_el, prime_el_pos, prime_el_count);
    }
    else
       res = 1;
          
    return res;
}