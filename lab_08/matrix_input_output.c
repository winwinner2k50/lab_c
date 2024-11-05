#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "matrix_input_output.h"

int num_input_int(void *pos)
{
    return scanf("%d", (int*)(pos));
}

void num_output_int(void *pos)
{
    printf("%d", *((int*)pos));
}


int num_input_double(void *pos)
{
    return scanf("%lf", (double*)(pos));
}

void num_output_double(void *pos)
{
    printf("%lf", *((double*)pos));
}

void num_double(void *num, double value)
{
    *(double*)num = value;
}



int matrix_unit_gen(void ***lins, size_t n, size_t m, size_t type_size, void (num_make)(void*, double))
{
    (*lins) = malloc(n * sizeof(char*));
    for (size_t i = 0; i < n; i++)
    {
        (*lins)[i] = malloc(m * type_size);
        
        for(size_t j = 0; j < m; j++)
        {
             if (j == i)
                num_make(((char*)(*lins)[i] + j * type_size), 1);
            else
                num_make(((char*)(*lins)[i] + j * type_size), 0);
        }
           
    }
    return 0;
}

int matrix_input(void ***lins, size_t n, size_t m, size_t type_size, int (f_input)(void*))
{
    (*lins) = malloc(n * sizeof(char*));
    
    for (size_t i = 0; i < n; i++)
    {
        (*lins)[i] = malloc(m * type_size);
        
        for(size_t j = 0; j < m; j++)
            f_input(((char*)(*lins)[i] + j * type_size));
    }
    return 0;
}


void matrix_output(void **lins, size_t n, size_t m, size_t type_size, void (f_output)(void*))
{
    for (size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            f_output(((char*)(lins)[i] + j * type_size));
            printf(" ");
        }

        printf("\n");
    }
}

