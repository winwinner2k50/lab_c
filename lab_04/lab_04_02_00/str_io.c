#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "str_io.h"

void arr_str_output(char arr_str[][LEN_WORD], int arr_count_words[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        printf("%s ", arr_str[i]);
        printf("%d\n", arr_count_words[i]);
    }
        
}

int word_in_arr(char arr_words[][LEN_WORD], char word[], size_t len_word, size_t arr_words_len, size_t *word_posit)
{
    int res = 0;
    for (size_t i = 0; i < arr_words_len; i++)
    {
        if (strncmp(arr_words[i], word, len_word) == 0 && res == 0)
        {
            res = 1;
            *word_posit = i;
        }   
    }
    return res;
}

void try_past_word(char arr_words[][LEN_WORD], int arr_count_words[], size_t *arr_words_len, char word[], size_t len_word)
{
    size_t word_posit;
    if (!word_in_arr(arr_words, word, len_word, *arr_words_len, &word_posit))
    {
        (*arr_words_len)++;
        strncpy(arr_words[(*arr_words_len) - 1], word, len_word); 
        arr_count_words[(*arr_words_len) - 1] = 1;
    }
    else
    {
        arr_count_words[word_posit]++;
    }
}

int try_find_words(char arr_words[][LEN_WORD], size_t *arr_words_len,  int arr_count_words[], char s[], size_t len_s)
{
    int res = 0;
    *arr_words_len = 0;

    char word[LEN];
    size_t len_word = 0;

    for (size_t i = 0; i < len_s; i++)
    {
        if (ispunct(s[i]) || isspace(s[i]) || s[i] == '\n')
        {
            if (len_word != 0)
            {
                if (len_word > 16)
                    res = 1;
                else
                    try_past_word(arr_words, arr_count_words, &arr_words_len, word, len_word);
                 
            } 
            len_word = 0;
        }
        else
        {
            len_word++;
            word[len_word - 1] = s[i];
        }
    }
    return res;
}





