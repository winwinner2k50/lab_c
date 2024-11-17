#include "film_struct.h"

#define ERROR_READ_DATA_FILE 10

int films_input_file(film **a, size_t *n, char file_name[], int (comparator)(film, film));

void films_output(film *a, size_t n);

int films_comparator_year(film a, film b);

int films_comparator_title(film a, film b);

int films_comparator_name(film a, film b);

void film_output(film a);