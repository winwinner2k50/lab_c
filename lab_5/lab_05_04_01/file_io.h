#include <stdio.h>

#define OK
#define SURNAME_LEN 25
#define NAME_LEN 10
#define ASSESSMENTS_COUNT 4
#define FILE_NAME_LEN 20
#define STUDENT_STRUCT_LEN NAME_LEN + SURNAME_LEN + ASSESSMENTS_COUNT * sizeof(unsigned int)


struct student
{
    int a;
    char surname[SURNAME_LEN];
    char name[NAME_LEN];
    unsigned int assessments[ASSESSMENTS_COUNT];
};

void students_input(char file_name[20], size_t n);

void students_output(char file_name[20]);

void students_dell(char file_name[20]);

void student_sort(char file_name[FILE_NAME_LEN]);

void student_find(char file_name[FILE_NAME_LEN], char subs[]);
