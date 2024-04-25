#include <stdio.h>
#include <string.h>
#include "str_io.h"

int main(void)
{
    char s[LEN];
    size_t n;

    char arr_words[LEN][LEN_WORD];
    int arr_count_words[LEN];
    
    size_t arr_words_len;

    
    
    if (fgets(s, LEN + 1, stdin) == NULL || (strlen(s) == LEN && s[LEN - 1] != '\n'))
    {
       printf("Ошибка ввода\n");
       return INPUT_ERROR;
    }
    n = strlen(s);
    
    arr_words_len = try_find_words(arr_words, arr_count_words, s, n);
    arr_str_output(arr_words, arr_count_words, arr_words_len);
    return 0;
}