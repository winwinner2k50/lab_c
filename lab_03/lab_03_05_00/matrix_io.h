#include <stdio.h>

#define LEN 10

#define ERROR_INPUT 1
#define ERROR_INPUT_MATRIX 2

#define OK 0

int input_matrix(int a[][LEN], size_t n, size_t m);

void out_matrix(int a[][LEN], size_t n, size_t m);

int find_remove_prime(int a[][LEN], size_t n, size_t m);