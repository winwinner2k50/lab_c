#define ERROR_FILE_INPUT_NULL 11
#define ERROR_READ_FIRST_LINE 12
#define FILE_NAME_LEN 100

int matrix_from_file(char ***lins, size_t *n, size_t *m, size_t tips_size, char file_name[], int (f_input)(char*, FILE*));

int matrix_clear(char ***lins, size_t n);

void matrix_output(char **lins, size_t n, size_t m, size_t tips_size, void (f_output)(char*));

int matrix_input(char ***lins, size_t n, size_t m, size_t tips_size, int (f_input)(char*));

int num_input_int(char *pos);

void num_output_int(char *pos);

int num_input_double(char *pos);

void num_output_double(char *pos);