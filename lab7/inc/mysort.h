#include <stddef.h>

void mysort(void *a, size_t size, size_t n, int ( * f ) ( const void *, const void * ));

int comparator_int(const void * val1, const void * val2);

int comparator_double(const void * val1, const void * val2);