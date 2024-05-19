#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "file_io.h"
int main(void)
{
    srand(time(NULL));
    FILE *f = fopen("q.txt", "wb");
    file_gen(f, 5);
    fclose(f);

    f = fopen("q.txt", "rb");
    file_output_el(f);
    fclose(f);

    f = fopen("q.txt", "rb");
    printf("\n%d\n",get_number_by_pos(f, 0));
    fclose(f);

    f = fopen("q.txt", "r+b");
    //file_sort_el(f, 5);
    fclose(f);

    printf("\n");
    f = fopen("q.txt", "rb");
    fseek(f, 0, SEEK_SET);
    file_output_el(f);
    fclose(f);



    return 0;
}