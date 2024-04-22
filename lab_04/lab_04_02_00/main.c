#include <stdio.h>
#include <string.h>
#include "str_io.h"

int main(void)
{
    char s[LEN];
    size_t n;

    char arr_words[LEN][LEN];
    int arr_count_words[LEN];
    
    size_t arr_words_len;

    fgets(s, LEN, stdin);
    n = strlen(s);
    if (s[n - 1] != '\n')
    {
        printf("fatal");
    }
    arr_words_len = count_words(arr_words, arr_count_words, s, n);
    arr_str_output(arr_words, arr_count_words, arr_words_len);
    
    return 0;
}