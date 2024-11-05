#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <math.h>

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

void multiply_double(void *a, void *b, void **res)
{
    *(double*)(*res) = fabs(*(double*)(a)) * fabs(*(double*)(b));
}

void num_sqrt_double(void **a, size_t n)
{
    *(double*)(*a) = pow((*(double*)(*a)), (double)(1/(double)n));
}


int matrix_geometric_col(void **el, size_t pos_y, void **lins, size_t n, size_t type_size, void (multiply)(void*, void*, void**), void (sqrt_my)(void**, size_t))
{
    *(double*)(*el) = 1;
    for (size_t i = 0; i < n; i++)
        multiply(*el, ((char*)lins[i] + pos_y * type_size), el);
        
    sqrt_my(el, n);
    return 0;
}

int matrix_max_min_str(void **el, size_t pos_x, void **lins, size_t m, size_t type_size, int (comparator)(void*, void*))
{
    *(double*)(*el) = *(double*)lins[pos_x];
    for (size_t j = 0; j < m; j++)
    { 
        if (comparator((char*)(lins)[pos_x] + j * type_size, *el))
            *(double*)(*el) = *(double*)((char*)(lins)[pos_x] + j * type_size);
    }  
    return 0;
}

void matrix_add_str_double(void ***lins, size_t *n, size_t *m, size_t type_size)
{
    (*n)++;
    (*lins) = realloc(*lins, (*n) * sizeof(char*));
    (*lins)[*n - 1] = malloc((*m) * sizeof(char*));
    for (size_t j = 0; j < *m; j++)
    {
        void *el = (char*)(*lins)[*n - 1] + j * type_size;
        matrix_geometric_col(&el, j, *lins, *n - 1, type_size, multiply_double, num_sqrt_double);
    }   
}

void matrix_add_col(void ***lins, size_t *n, size_t *m, size_t type_size)
{
    (*m)++;
    for (size_t i = 0; i < (*n); i++)
        (*lins)[i] = realloc((*lins)[i], (*m) * sizeof(char*));
    for (size_t i = 0; i < *n; i++)
    {
        void *el = (char*)(*lins)[i] + (*m - 1) * type_size;
        matrix_max_min_str(&el, i, *lins, *m, type_size, num_min_double);
    }
}

// int matrix_add(void ***lins, size_t *n, size_t *m, size_t type_size, void (operation)(void***, size_t*, size_t*, size_t))
// {
//     //нахуй??? а может и да бля
//     // и всё же хуйня
// }

void matrix_magnification(void ***lins, size_t *n, size_t *m, size_t type_size, size_t number_operations, void (add_col)(void***, size_t*, size_t*, size_t), void (add_str)(void***, size_t*, size_t*, size_t))
{
    for (size_t i = 0; i < number_operations; i++)
        add_str(lins, n, m, type_size);

    for (size_t i = 0; i < number_operations; i++)
        add_col(lins, n, m, type_size);
}

int matrixes_equal_size(void ***a, size_t *n, size_t *m, void ***b, size_t *p, size_t *q, size_t type_size, void (add_col)(void***, size_t*, size_t*, size_t), void (add_str)(void***, size_t*, size_t*, size_t))
{
    while (*n != *p)
    {
        if (*n < *p)
            add_str(a, n, m, type_size);
        else
            add_str(b, p, q, type_size);
    }
    while (*m != *q)
    {
        if (*m < *q)
            add_col(a, n, m, type_size);
        else
            add_col(b, p, q, type_size);
    }
    return 0;
} 

int matrix_clear(void ***lins, size_t n)
{
    for (size_t i = 0; i < n; i++)
        free((*lins)[i]);
    free(*lins);
    return 0;
}