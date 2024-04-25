#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define LEN 100


char *my_strpbrk(char a[], char b[])
{
    
    for (char *i = a; (*i) != '\0'; i++)
        for (char *j = b; (*j) != '\0'; j++)
            if ((*j) == (*i))
                return i;
    return NULL;
}

size_t my_strcspn( const char * string1, const char * string2)
{
    size_t i = 0;
    for (i = 0; string1[i] != '\0'; i++)
        for (size_t j = 0; string2[j] != '\0'; j++)
            if (string1[i] == string2[j])
                return i;
    return i;
}

char *my_strrchr(char string[], int symbol)
{
    char *res = NULL;
    char *i;
    for (i = string; (*i) != '\0'; i++)
            if ((*i) == (char)symbol)
                res = i;
    if (*i == (char)symbol)
        res = i;
    return res;
}




