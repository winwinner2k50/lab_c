#include <stdio.h>

#define LEN 10

#define ERROR_INPUT 1
#define ERROR_INPUT_MATRIX 2
#define ERROR_NOT_POS 3

#define OK 0


int input_matrix(int a[][LEN], size_t n, size_t m);

int try_find_min_pos(int a[][LEN], int *min, size_t n, size_t m);

