#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "file_io.h"

int main(int argc, char **argv)
{
    if (argc == 0)
    {
        printf("ERROR");
        return 1;
    }
        
    if (strcmp(argv[1], "sb") == 0)
    {
        student_sort(argv[2]);
    }


        
}