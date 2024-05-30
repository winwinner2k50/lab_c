#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "file_io.h"

int main(int argc, char **argv)
{    
    if (strcmp(argv[1], "sb") == 0)
    {
        if (argc != 3)
            return ERROR_ARGS;
        return student_sort(argv[2]);
    }

    if (strcmp(argv[1], "fb") == 0)
    {
        if (argc != 5)
            return ERROR_ARGS;
        return student_find(argv[2], argv[3], argv[4]);
    }

    if (strcmp(argv[1], "db") == 0)
    {
        if (argc != 3)
            return ERROR_ARGS;
        return students_dell(argv[2]);
    }

    if (strcmp(argv[1], "import") == 0)
        return file_import(argv[2], argv[3]);
        

    if (strcmp(argv[1], "export") == 0)
        return file_export(argv[2], argv[3]);

    if (strcmp(argv[1], "p") == 0)
        students_output(argv[2]);

    if (strcmp(argv[1], "g") == 0)
        students_input(argv[2], 3);

    return ERROR_ARGS;
}