#include <stdio.h>

#define LEN 257
#define LEN_WORD 16
#define INPUT_ERROR 1

size_t try_find_words(char arr_words[][LEN_WORD], int arr_count_words[], char s[], size_t len_s);

void arr_str_output(char arr_str[][LEN_WORD], int arr_count_words[], size_t n);