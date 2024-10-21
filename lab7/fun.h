#define FILE_NAME_LEN 100

#define ERROR_FILE_NULL 101
#define ERROR_NUMS_COUNT 102

#define ERROR_FILE_DATA 201

int file_nums_count(size_t *n, char file_name[]);

int arr_gen(int **a, int **a_end, char file_name[]);

int arr_output(int a[], size_t n);

int key(const int *a, const int *a_end, int **b, int **b_end);

void arr_output_new(int *a, int *a_end);

void mysort(void *a, size_t size, size_t n, int ( * f ) ( const void *, const void * ));

int comparator_int(const void * val1, const void * val2);
