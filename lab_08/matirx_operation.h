void matrix_dell_col(void ***lins, size_t *n, size_t *m, size_t type_size, size_t pos_x, size_t pos_y);

void matrix_dell_str(void ***lins, size_t *n, size_t *m, size_t type_size, size_t pos_x, size_t pos_y);

int matrix_find_el(void **lins, size_t n, size_t m, size_t type_size, void **el_found, size_t *x, size_t *y, int (comparator)(void*, void*));

int matrix_dell_something_with_el(void ***lins, size_t *n, size_t *m, size_t type_size,
int (comparator)(void*, void*), 
void (f_dell)(void***, size_t*, size_t*, size_t, size_t, size_t));

int matrix_geometric_col(void **el, size_t pos_y, void **lins, size_t n, size_t type_size, void (multiply)(void*, void*, void**), void (sqrt_my)(void**, size_t));

void num_sqrt_double(void **a, size_t n);

void multiply_double(void *a, void *b, void **res);

void matrix_add_col(void ***lins, size_t *n, size_t *m, size_t type_size);

void matrix_add_str_double(void ***lins, size_t *n, size_t *m, size_t type_size);

int num_max_double(void *a, void *b);

int num_min_double(void *a, void *b);

int matrix_clear(void ***lins, size_t n);

int matrixes_equal_size(void ***a, size_t *n, size_t *m, void ***b, size_t *p, size_t *q, size_t type_size, void (add_col)(void***, size_t*, size_t*, size_t), void (add_str)(void***, size_t*, size_t*, size_t));

int matrixes_multiply(void **a, void **b, void ***res,
                      size_t n,
                      size_t type_size,
                      void (multiply)(void*, void*, void**),
                      void (sum)(void*, void*, void*),
                      void (num_make)(void*, double));

void sum_double(void *a, void *b, void *res);

void matrix_magnification(void ***lins, size_t *n, size_t *m, size_t type_size, size_t number_operations, void (add_col)(void***, size_t*, size_t*, size_t), void (add_str)(void***, size_t*, size_t*, size_t));

