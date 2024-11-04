#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "matrix_input_output.h"
#include "matirx_operation.h"

int num_max_int(void *a, void *b)
{
    return *((int*) a) >= *((int*) b);
}

int num_min_int(void *a, void *b)
{
    return *((int*) a) <= *((int*) b);
}

int num_max_double(void *a, void *b)
{
    return *((double*) a) >= *((double*) b);
}

int num_min_double(void *a, void *b)
{
    return *((double*) a) <= *((double*) b);
}

void swap(void *a, void *b, size_t type_size)
{
    for (size_t i = 0; i < type_size; i++)
    {
        char tmp = *((char*)a + i);
        *((char*)a + i) = *((char*)b + i);
        *((char*)b + i) = tmp;
    }
}

void matrix_dell_str(void ***lins, size_t *n, size_t *m, size_t type_size, size_t pos_x, size_t pos_y)
{
    pos_y = 0; // да это костыль, но он мне нужен что бы достигнуть одинаковой сигнатуры функции
    for (size_t i = pos_x; i < (*n) - 1; i++)
    {
        for(size_t j = pos_y; j < (*m); j++)
        {
            void *x = (char*)(*lins)[i] + j * type_size;
            void *y = (char*)(*lins)[i + 1] + j * type_size;
            swap(x, y, type_size);
        }
    }
    free((*lins)[(*n) - 1]);
    (*n)--;
    (*lins) = realloc(*lins, (*n) * sizeof(char*));
}

void matrix_dell_col(void ***lins, size_t *n, size_t *m, size_t type_size, size_t pos_x, size_t pos_y)
{
    pos_x = 0; // да это костыль, но он мне нужен что бы достигнуть одинаковой сигнатуры функции
    for(size_t j = pos_y; j < (*m) - 1; j++)
    {
        for (size_t i = pos_x; i < (*n); i++)
        {
            void *x = (char*)(*lins)[i] + j * type_size;
            void *y = (char*)(*lins)[i] + (j + 1) * type_size;
            swap(x, y, type_size);
        }
    }
    (*m)--;
    for (size_t i = 0; i < (*n); i++)
        (*lins)[i] = realloc((*lins)[i], (*m) * sizeof(char*));
}

int matrix_find_el(void **lins, size_t n, size_t m, size_t type_size, void **el_found, size_t *x, size_t *y, int (comparator)(void*, void*))
{
    *x = 0;
    *y = 0;
    *el_found = (char*)(lins)[0];
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
        {
            void *el = (char*)(lins)[i] + j * type_size;
            if (comparator(el, *el_found))
            {
                *el_found = el;
                *x = i;
                *y = j;
            }
                
        }
    return 0;
}

int matrix_dell_something_with_el(void ***lins, size_t *n, size_t *m, size_t type_size,
int (comparator)(void*, void*), 
void (f_dell)(void***, size_t*, size_t*, size_t, size_t, size_t))
{
    void *el;
    size_t x;
    size_t y;
    matrix_find_el(*lins, *n, *m, type_size, &el, &x, &y, comparator);
    f_dell(lins, n, m, type_size, x, y);
    return 0;
}

int matrix_square_with_dell(void ***lins, size_t *n, size_t *m, size_t type_size, int (comparator)(void*, void*))
{
    while (*n != *m)
    {
        if (*n > *m)
            matrix_dell_something_with_el(lins, n, m, type_size, comparator, matrix_dell_str);
        else
            matrix_dell_something_with_el(lins, n, m, type_size, comparator, matrix_dell_col);
    }
    return 0;
}

// int matrix_add_str(void ***lins, size_t *n, size_t *m, size_t type_size, size_t pos_x, size_t pos_y)
// {
//     (*n)++;
//     (*lins) = realloc(*lins, (*n) * sizeof(char*));

// }

int matrix_clear(void ***lins, size_t n)
{
    for (size_t i = 0; i < n; i++)
        free((*lins)[i]);
    free(*lins);
    return 0;
}