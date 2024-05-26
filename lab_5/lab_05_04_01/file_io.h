#include <stdio.h>

#define OK
#define SURNAME_LEN 25
#define NAME_LEN 10
#define ASSESSMENTS_COUNT 4
#define FILE_NAME_LEN 20

#define ERROR_ARGS 1
#define ERROR_FILE 2


struct student
{
    int a;
    char surname[SURNAME_LEN];
    char name[NAME_LEN];
    unsigned int assessments[ASSESSMENTS_COUNT];
};

void students_input(char file_name[20], size_t n);

void students_output(char file_name[20]);

int students_dell(char file_name[20]);

int student_sort(char file_name[FILE_NAME_LEN]);

int student_find(char file_new_name[FILE_NAME_LEN], char file_name[FILE_NAME_LEN], char subs[]);