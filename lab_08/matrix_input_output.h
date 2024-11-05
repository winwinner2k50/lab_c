#define ERROR_FILE_INPUT_NULL 11
#define ERROR_READ_FIRST_LINE 12
#define FILE_NAME_LEN 100

int matrix_input(void ***lins, size_t n, size_t m, size_t tips_size, int (f_input)(void*));

void matrix_output(void **lins, size_t n, size_t m, size_t tips_size, void (f_output)(void*));

int matrix_square_with_dell(void ***lins, size_t *n, size_t *m, size_t type_size, int (comparator)(void*, void*));

int matrix_unit_gen(void ***lins, size_t n, size_t m, size_t type_size, void (num_make)(void*, double));

void num_double(void *num, double value);

int num_input_int(void *pos);

void num_output_int(void *pos);

int num_input_double(void *pos);

void num_output_double(void *pos);

void multiply_double_fabs(void *a, void *b, void **res);



