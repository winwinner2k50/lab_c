#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "matrix_input_output.h"
#include "matirx_operation.h"

void swap(void *a, void *b, size_t type_size)
{
    for (size_t i = 0; i < type_size; i++)
    {
        char tmp = *((char*)a + i);
        *((char*)a + i) = *((char*)b + i);
        *((char*)b + i) = tmp;
    }
}

void matrix_dell_str(void ***lins, size_t pos, size_t type_size, size_t *n, size_t m)
{
    for (size_t i = pos; i < (*n) - 1; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            void *x = (char*)(*lins)[i] + j * type_size;
            void *y = (char*)(*lins)[i + 1] + j * type_size;
            swap(x, y, type_size);
        }
    }
    (*n)--;
}

void matrix_dell_col(void ***lins, size_t pos, size_t type_size, size_t n, size_t *m)
{
    for(size_t j = pos; j < (*m) - 1; j++)
    {
        for (size_t i = 0; i < n; i++)
        {
            void *x = (char*)(*lins)[i] + j * type_size;
            void *y = (char*)(*lins)[i] + (j + 1) * type_size;
            swap(x, y, type_size);
        }
    }
    (*m)--;
}

// void matrix_find_el(void ***lins, size_t)

int matrix_clear(void ***lins, size_t n)
{
    for (size_t i = 0; i < n; i++)
        free((*lins)[i]);
    free(*lins);
    return 0;
}