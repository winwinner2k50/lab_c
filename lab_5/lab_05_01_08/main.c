#include <stdio.h>
#include <string.h>
#include "file_io.h"
int main(void)
{
    FILE *f = fopen("q.txt", "r");
    int len_loc_max;
    process(f, &len_loc_max);
    printf("%d\n", len_loc_max);
    fclose(f);
    return 0;
}