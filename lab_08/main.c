#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "matrix.h"

int main(void)
{
    char file_name[FILE_NAME_LEN];
    size_t n, m;
    printf("Введите имя файла:\n");
    scanf("%s", file_name);
    char **lins;

    matrix_from_file(&lins, &n, &m, sizeof(double), file_name, num_input_double);
    matrix_output(lins, n, m, sizeof(double), num_output_double);

    matrix_clear(&lins, n);
    return 0;
}