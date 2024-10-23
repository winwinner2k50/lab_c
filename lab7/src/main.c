#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "mysort.h"
#include "key.h"
#include "arr.h"

// int main(void)
// {

// }

int main(void)
{
    int *a = NULL, *a_end = NULL;
    int *filter = NULL, *filter_end = NULL;

    char file_name[FILE_NAME_LEN];
    scanf("%s", file_name);

    arr_gen(&a, &a_end, file_name);

    key(a, a_end, &filter, &filter_end);
    
    arr_output_int(filter, filter_end);
    
    mysort(filter, sizeof(int), filter_end - filter, comparator_int); // возможно переданно не то значение третьего параметра
    arr_output_int(filter, filter_end);
    free(a);
    free(filter);
    return 0;
}