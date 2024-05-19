#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "file_io.h"

int main(void)
{
    srand(time(NULL));
    students_input("q.bin", 5);
    students_output("q.bin");
    students_dell("q.txt");
    students_output("q.bin");
}