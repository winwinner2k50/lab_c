#include <stdio.h>

#define OK
#define SURNAME_LEN 25
#define NAME_LEN 10
#define ASSESSMENTS_COUNT 4
#define FILE_NAME_LEN 20

#define ERROR_ARGS 53
#define ERROR_FILE 2


struct student
{
    char surname[SURNAME_LEN + 1];
    char name[NAME_LEN + 1];
    unsigned int assessments[ASSESSMENTS_COUNT];
};

void students_input(char file_name[], size_t n);

void students_output(char file_name[]);

int students_dell(char file_name[]);

int student_sort(char file_name[]);

int student_find(char file_name[], char file_new_name[], char subs[]);

int file_export(char file_bin_name[], char file_txt_name[]);

int file_import(char file_txt_name[], char file_bin_name[]);