#include <stdio.h>
#include <string.h>
#include "file_io.h"
int main(void)
{
    int len_loc_max;
    if (process(stdin, &len_loc_max))
    {
        printf("Ошибка ввода");
        return ERROR_INPUT;
    }
        
    printf("%d\n", len_loc_max);
    return 0;
}