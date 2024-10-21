#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "arr.h"


int arr_output_old(int a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    return 0;
}

void arr_output_int(int *a, int *a_end)
{
    while (a < a_end)
    {
        printf("%d ", *a);
        a++;   
    }
    printf("\n");;
}

void arr_output_double(double *a, double *a_end)
{
    while (a < a_end)
    {
        printf("%lf ", *a);
        a++;   
    }
    printf("\n");
}


int file_nums_count(size_t *n, char file_name[])
{
    *n = 0;
    FILE *f = fopen(file_name, "r+");
    if (f == NULL)
        return ERROR_FILE_NULL;

    int a;

    while(fscanf(f, "%d", &a) == 1)
        (*n)++;

    if (*n == 0)
        return ERROR_NUMS_COUNT;

    if(!feof(f))
        return ERROR_NOT_END_FILE;
        
    fclose(f);

    return 0;
}

int arr_gen(int **a, int **a_end, char file_name[])
{
    int res = 0;
    size_t n;

    res = file_nums_count(&n, file_name);

    FILE *f = fopen(file_name, "r+");
    *a = malloc(n * sizeof(int));

    int *el = *a;
    while(el < *a + n)
    {
        if(fscanf(f, "%d", el) != 1)
            res = ERROR_FILE_DATA;
        el++;
    }
    *a_end = el;
    fclose(f);
    return res;
}