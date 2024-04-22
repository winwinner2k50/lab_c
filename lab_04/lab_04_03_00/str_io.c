#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "str_io.h"


void words_output(char arr_words[][LEN], size_t arr_words_len)
{
    for (size_t i = 0; i < arr_words_len; i++)
        printf("%s\n", arr_words[i]);
}

/*
int word_in_arr(char arr_words[][LEN], char word[], size_t len_word, size_t arr_words_len)
{
    int res = 0;
    for (size_t i = 0; i < arr_words_len; i++)
    {
        if (strncmp(arr_words[i], word, len_word) == 0 && res == 0)
        {
            res = 1;
        }   
    }
    return res;
}
*/

void past_num(char arr_words[][LEN], size_t *arr_words_len, char word[], size_t len_word)
{
    (*arr_words_len)++;
    strncpy(arr_words[(*arr_words_len) - 1], word, len_word);   
}

size_t count_nums(char arr_words[][LEN], char s[], size_t len_s)
{
    size_t arr_words_len = 0;

    char word[LEN];
    size_t len_word = 0;

    for (size_t i = 0; i < len_s; i++)
    {
        if (isspace(s[i]))
        {
           // str_output(word, len_word);
            past_num(arr_words, &arr_words_len, word, len_word);
            len_word = 0;
        }
        else
        {
            len_word++;
            word[len_word - 1] = s[i];
        }
    }
    return arr_words_len;
}

void swap_str(char a[LEN], char b[LEN])
{
    char c[LEN];
    strncpy(c, a, LEN);
    strncpy(a, b, LEN);
    strncpy(b, c, LEN);
}

void revers_arr(char a[LEN][LEN], size_t n)
{
    for (size_t i = 0; i < n / 2; i++)
    {
        swap_str(a[i], a[n - i -1]);
    }
}

void swap_el(char *a, char *b)
{
    char c = *a;
    *a = *b;
    *b = c;
}

void remove_el_word(char word[], size_t *n, size_t posit)
{
    for (size_t i = posit; i < *n - 1; i++)
    {
        word[i] = word[i + 1];
    }
    word[*n - 1] = '\0';
    (*n)--;
}

void replace_word(char word[])
{
    size_t n = strlen(word);
    char first_el = word[0];
    for (size_t i = 1; i < n; i++)
    {
        if (first_el == word[i])
        {
            remove_el_word(word, &n, i);
            i--;
        }
    }
}

void replace_words(char arr_words[][LEN], size_t arr_words_len)
{
    for (size_t i = 0; i < arr_words_len; i++)
    {
        replace_word(arr_words[i]);
    }
}

void gen_str(char s[], char arr_words[][LEN], size_t arr_words_len)
{
    size_t len_str = 0;
    revers_arr(arr_words, arr_words_len);
    replace_words(arr_words, arr_words_len);
    for (size_t i = 1; i < arr_words_len; i++)
    {
        for (size_t j = 0; arr_words[i][j] != '\0'; j++)
        {
            len_str++;
            s[len_str - 1] = arr_words[i][j];
        }
        if (i + 1 != arr_words_len)
        {   
            len_str++;
            s[len_str - 1] = ' ';
        }
    }
}

