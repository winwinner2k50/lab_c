#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "film_find.h"
#include "film_io.h"

void film_gen_key(film *a, char field[], char key[])
{
    a->title = strdup("-");
    a->name = strdup("-");
    a->year = -1;
    if (strcmp("title", field) == 0)
        a->title = strdup(key);
    if (strcmp("name", field) == 0)
        a->name = strdup(key);
    if (strcmp("year", field) == 0)
        a->year = atoi(key);
}

int film_find(film *a, size_t n, film el, size_t *pos, int (comparator)(film, film))
{
    size_t left = 0;
    size_t right = n;
    while (right > left)
    {
        
        size_t mid = (left + right) / 2;
        // printf("-----\n");
        // film_output(a[mid]);
        // film_output(el);
        // printf("%d\n", comparator(a[mid], el));
        // printf("-----\n");
        if (comparator(a[mid], el) == 0)
        {
            
            *pos = mid;
            return 0;
        }
        else if (comparator(a[mid], el) < 0)
            left = mid + 1;
        else
            right = mid;
    }
    return 1;
    
}