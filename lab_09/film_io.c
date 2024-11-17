#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "film_struct.h"
#include "film_io.h"

int films_comparator_name(film a, film b)
{
    return strcmp(a.name, b.name) < 0;
}

int films_comparator_title(film a, film b)
{
    return strcmp(a.title, b.title) < 0;
}

int films_comparator_year(film a, film b)
{
    return a.year < b.year;
}

void str_init(char *str) {
    size_t len = strcspn(str, "\n"); 
    str[len] = '\0';              
}

int film_file_read(film *a, FILE *f)
{
    int res = 0;
    a->title = NULL;
    a->title_len = 0;
    a->name = NULL;
    a->name_len = 0;
    if (getline(&a->title, &a->title_len, f) == -1)
        res = ERROR_READ_DATA_FILE;

    if (getline(&a->name, &a->name_len, f) == -1)
        res = ERROR_READ_DATA_FILE;

    if (fscanf(f, "%d\n", &a->year) != 1)
        res = ERROR_READ_DATA_FILE;

    str_init(a->name);
    str_init(a->title);
    
    return res;
}

int film_clear(film *a)
{
    free(a->name);
    free(a->title);
    return 0;
}

void file_copy(film *a, film b)
{
    (*a).name = strdup(b.name);
    (*a).title = strdup(b.title);
    (*a).year = b.year;
}

void films_swap(film *a, film *b)
{
    film el;
    file_copy(&el, *a);
    file_copy(a, *b);
    file_copy(b, el);
    film_clear(&el);
}

void films_find_pos(film *a, size_t n, film el, size_t *pos, int (comparator)(film, film))
{
    while( *pos < n && comparator(a[*pos], el) )
        (*pos)++;
}

int films_add_el(film **a, size_t *n, film el, size_t pos)
{
    (*n)++;
    *a = realloc(*a, (*n) * sizeof(film));

    for (size_t i = *n - 1; i > pos; i--)
        file_copy(&(*a)[i], (*a)[i - 1]);
    
    file_copy(&(*a)[pos], el);

    return 0;
}

int films_input_file(film **a, size_t *n, char file_name[], int (comparator)(film, film))
{
    FILE *f = fopen(file_name, "r"); 
    film el;
    *n = 0;
    while(film_file_read(&el, f) == 0)
    {
        size_t pos = 0;
        films_find_pos(*a, *n, el, &pos, comparator);
        films_add_el(a, n, el, pos);
        film_clear(&el);
    }
    fclose(f);
}

void films_output(film *a, size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%s %s %d\n", a[i].name, a[i].title, a[i].year);
}

