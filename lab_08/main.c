#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "matrix.h"

int main(void)
{
    char file_name[] = "a.txt";
    size_t n, m;

    char **lins;

    matrix_from_file(&lins, &n, &m, sizeof(int), file_name, num_input_int);
    matrix_output(lins, n, m, sizeof(int));

    matrix_clear(&lins, n);
    return 0;
}