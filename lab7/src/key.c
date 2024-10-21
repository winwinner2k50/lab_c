#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "key.h"

int *arr_find_max(const int *a, const int *a_end)
{
    const int *max = a;
    while (a < a_end)
    {
        if (*max < *a)
            max = a;
        a++;
    }
    return (int*)max;
}

int *arr_find_min(const int *a, const int *a_end)
{
    const int *min = a;
    while (a < a_end)
    {
        if (*min > *a)
            min = a;
        a++;
    }
    return (int*)min;
}

void swap_any(void *a, void* b, size_t s)
{
    void* tmp = malloc(s);
    memcpy(tmp, a, s);
    memcpy(a, b, s);
    memcpy(b, tmp, s);
    free(tmp);
}

int key(const int *a, const int *a_end, int **b, int **b_end)
{
    int *pos1 = arr_find_min(a, a_end);
    int *pos2 = arr_find_max(a, a_end);

    

    if (pos1 > pos2)
        swap_any(&pos1, &pos2, sizeof(&pos2));

    if (pos2 - pos1 - 1 <= 0)
        return ERROR_NOT_DATA;

    *b = malloc((pos2 - pos1 - 1) * sizeof(int));
    *b_end = *b + (pos2 - pos1 - 1);

    int *el = *b;

    pos1++;
    while (el < *b_end && pos1 < pos2)
    {
        (*el) = *(pos1);
        el++;
        pos1++;
    }
    return 0;
}