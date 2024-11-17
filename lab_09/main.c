#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "film_io.h"
#include "film_struct.h"

int main(void)
{
    film *a = NULL;
    size_t n = 0;
    films_input_file(&a, &n, "a.txt", films_comparator_name);
    films_output(a, n);
    return 0;
}