#include <stdio.h>
#include <string.h>
#include "str_io.h"

int main(void)
{
    char s[LEN];
    size_t n;

    char words[LEN][LEN];
    size_t words_len;

    char str_new[LEN];

    fgets(s, LEN, stdin);
    n = strlen(s);
    
    words_len = count_nums(words, s, n);
    gen_str(str_new, words, words_len);
   // words_output( words, words_len);
    printf("%s\n", str_new);
    return 0;
}