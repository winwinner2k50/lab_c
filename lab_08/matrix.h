#define ERROR_FILE_INPUT_NULL 11
#define ERROR_READ_FIRST_LINE 12
#define FILE_NAME_LEN 100

int matrix_from_file(char ***lins, size_t *n, size_t *m, size_t tips_size, char file_name[], int (f_input)(char*, FILE*));

int matrix_clear(char ***lins, size_t n);

int matrix_output(char **lins, size_t n, size_t m, size_t tips_size);

int num_input_int(char *pos, FILE *f);