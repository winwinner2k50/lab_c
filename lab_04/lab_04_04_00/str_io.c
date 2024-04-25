#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "str_io.h"


void words_output(char arr_words[][LEN], size_t arr_words_len)
{
    for (size_t i = 0; i < arr_words_len; i++)
        printf("%s\n", arr_words[i]);
}


void past_word(char arr_nums[][LEN], size_t *arr_nuns_len, char num[], size_t len_num)
{
    (*arr_nuns_len)++;
    strncpy(arr_nums[(*arr_nuns_len) - 1], num, len_num);   
}

size_t count_nums(char arr_nums[][LEN], char s[], size_t len_s)
{
    size_t arr_words_len = 0;

    char num[LEN];
    size_t len_num = 0;

    for (size_t i = 0; i < len_s; i++)
    {
        if (s[i] == '.' || i + 1 == len_s)
        {
            past_word(arr_nums, &arr_words_len, num, len_num);
            len_num = 0;
        }
        else
        {
            len_num++;
            num[len_num - 1] = s[i];
        }
    }
    return arr_words_len;
}

int try_str_int(char s[], int *num)
{
    int res = 0;
    size_t n = strlen(s);
    for (size_t i = 0; i < n; i++)
    {
        if (!isdigit(s[i]))
            res = 1;
    }
    if (res == 0)
    {
        *num = atoi(s);
    }
    return res;
}

int num_is_pos(int a)
{
    return a >= 0 && a <= 255;
}

int num_str_pos(char s[])
{
    int res = 0;
    int num;
    size_t n = strlen(s);
    if (n > 3)
    {
        res = 1;
    } 
    else if (try_str_int(s, &num) || !(num_is_pos(num)))
        res = 1;

    return res;
    
}

int nums_is_ip(char arr_nums[][LEN], size_t len_s)
{
    int res = 0;
    if (len_s != 4)
        res = 1;
    else
    {
        for (size_t i = 0; i < len_s; i++)
        {
            if (num_str_pos(arr_nums[i]))
                res = 1;
        }
    }

    return res;
}


