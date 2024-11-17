#ifndef FILM_STRUCT_H
#define FILM_STRUCT_H

#define MAX_LEN_NAME 100
#define MAX_LEN_TITLE 100

typedef struct film
{
    int year;
    char *name;
    size_t name_len;
    char *title;
    size_t title_len;
} film;

#endif // FILM_STRUCT_H