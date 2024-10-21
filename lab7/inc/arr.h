#include <stddef.h>

#ifndef ARR_H
#define ARR_H

#define FILE_NAME_LEN 100

#define ERROR_FILE_NULL 101
#define ERROR_NUMS_COUNT 102
#define ERROR_NOT_END_FILE 103

#define ERROR_FILE_DATA 201

int file_nums_count(size_t *n, char file_name[]);

int arr_gen(int **a, int **a_end, char file_name[]);

void arr_output_int(int *a, int *a_end);

void arr_output_double(double *a, double *a_end);

#endif
