#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "film_io.h"
#include "film_struct.h"
#include "film_find.h"

int main(int argc, char **argv)
{
    film *a = NULL;
    size_t n = 0;
    films_input_file(&a, &n, argv[1], films_comparator_name);
    films_output(a, n);
    printf("\n");
    film el;
    film_gen_key(&el, argv[2], argv[3]);

    size_t pos = 0;
    film_find(a, n, el, &pos, films_comparator_name);
    film_output(a[pos]);
    
    return 0;
}