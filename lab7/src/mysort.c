#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "mysort.h"



void swap(void *a, void* b, size_t s)
{
    void* tmp = malloc(s);
    memcpy(tmp, a, s);
    memcpy(a, b, s);
    memcpy(b, tmp, s);
    free(tmp);
}

int comparator_int(const void * val1, const void * val2)
{
    if (*(int*)val1 > *(int*)val2)
        return 1;
    if (*(int*)val1 < *(int*)val2)
        return -1;
    return 0;
}

int comparator_double(const void * val1, const void * val2)
{
    if (*(double*)val1 > *(double*)val2)
        return 1;
    if (*(double*)val1 < *(double*)val2)
        return -1;
    return 0;
}

void mysort(void *a, size_t size, size_t n, int ( * f ) ( const void *, const void * ))
{
    n--; // костыль позже разобраться
    int multiplicity = 1;
    for (char *el1 = (char*)a; el1 < (char*)a + n * size; el1 += size)
    {
        if (multiplicity)
        {
           multiplicity = 0;
            for (char *el2 = (char*)a; el2 < (char*)a + n * size; el2 += size)
                if (f(el2, el2 + size) > 0)
                    swap(el2, el2 + size, size);
        }
        else
        {
            multiplicity = 1;
             for (char *el2 = (char*)a + n * size - size; el2 > (char*)a; el2 -= size)
                if (f(el2, el2 - size) < 0)
                   swap(el2, el2 - size, size);
        }
    }
}