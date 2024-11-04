void matrix_dell_col(void ***lins, size_t *n, size_t *m, size_t type_size, size_t pos_x, size_t pos_y);

void matrix_dell_str(void ***lins, size_t *n, size_t *m, size_t type_size, size_t pos_x, size_t pos_y);

int matrix_find_el(void **lins, size_t n, size_t m, size_t type_size, void **el_found, size_t *x, size_t *y, int (comparator)(void*, void*));

int matrix_dell_something_with_el(void ***lins, size_t *n, size_t *m, size_t type_size,
int (comparator)(void*, void*), 
void (f_dell)(void***, size_t*, size_t*, size_t, size_t, size_t));

int num_max_double(void *a, void *b);

int num_min_double(void *a, void *b);

int matrix_clear(void ***lins, size_t n);