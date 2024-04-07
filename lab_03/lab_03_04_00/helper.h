#include <stdio.h>

#define LEN 10

#define ERROR_INPUT 1
#define ERROR_INPUT_MATRIX 2
#define ERROR_NOT_POS 3

#define OK 0


int input_matrix(int a[][LEN], int n);

void out_matrix(int a[][LEN], int n);

int try_find_maxpos_num(int a[][LEN], int n, int *max);

