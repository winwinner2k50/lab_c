#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "file_io.h"
int main(int argc, char **argv)
{
    if (argc < 3)
    {
        return 1;
    }
        
    if (strcmp(argv[1], "p") == 0)
    {
        FILE *f = fopen(argv[2], "r");
        file_output_el(f);
    }

    if (strcmp(argv[1], "s") == 0)
    {
        FILE *f = fopen(argv[2], "r+");
        file_sort_el(f);
    }

    if (strcmp(argv[1], "c") == 0)
    {
        if (argc < 4)
            return 1;
        FILE *f = fopen(argv[3], "w");
        file_gen(f, atoi(argv[2]));
    }
    return 0;
}