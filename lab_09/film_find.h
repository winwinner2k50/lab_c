#include "film_struct.h"

void film_gen_key(film *a, char field[], char key[]);

int film_find(film *a, size_t n, film el, size_t *pos, int (comparator)(film, film));