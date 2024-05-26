#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "file_io.h"


size_t file_count_el(FILE *f)
{
    struct student a;
    size_t res = 0;
    fseek(f, 0, SEEK_SET);
    while (fread(&a, sizeof(struct student), 1, f) == 1)
        res++;
    fseek(f, 0, SEEK_SET);
    return res;
}

int get_student_by_pos(struct student *st, FILE *f, size_t pos)
{
    fseek(f, pos * sizeof(struct student), SEEK_SET);
    int res = fread(st, sizeof(struct student), 1, f);
    if (res == 1)
        return 0;
    return 1;
}

void put_student_by_pos(FILE *f, size_t pos, struct student el)
{
    fseek(f, sizeof(struct student) * pos, SEEK_SET);
    fwrite(&el, sizeof(struct student), 1, f);
}

void file_swap(FILE *f, size_t i, size_t j)
{
    
    struct student a;
    get_student_by_pos(&a, f, i);
    struct student b;
    get_student_by_pos(&b, f, j);
    put_student_by_pos(f, i, b);
    put_student_by_pos(f, j, a);
}

void arr_input(unsigned int a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        scanf("%u", &a[i]);
    char bl;
    scanf("%c", &bl);
}

void str_input(char s[], size_t n)
{
    int ch;
    size_t i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
        if (i < n - 1)
            s[i++] = ch;
    s[i] = '\0';
}

void arr_output(unsigned int a[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void students_output(char file_name[20])
{
    printf("\n");
    FILE *f = fopen(file_name, "rb");
    struct student st;
    rewind(f);
    for (size_t i = 0; fread(&st, sizeof(struct student), 1, f) == 1; i++)
    {
        //printf("%zu\n",ftell(f));
        //fseek(f, sizeof(struct student) * i, SEEK_SET);
        printf("%s %s\n", st.name, st.surname);
        arr_output(st.assessments, 4);
    }
    fclose(f);
}

void students_input(char file_name[20], size_t n)
{
    FILE *f = fopen(file_name, "wb");
    for (size_t i = 0; i < n; i++)
    {
        struct student st;
        printf("имя: ");
        str_input(st.name, NAME_LEN);
        printf("фамилия: ");
        str_input(st.surname, SURNAME_LEN);
        arr_input(st.assessments, 4);
        fwrite(&st, sizeof(struct student), 1, f);
    }
    fclose(f);
}

double average_assessments(unsigned int a[])
{
    double res = 0;
    for (size_t i = 0; i < ASSESSMENTS_COUNT; i++)
        res += a[i];
    return res / 4.0;
}

void file_dell_last_el(char file_name[20], size_t n)
{
    FILE *f = fopen(file_name, "rb");
    FILE *f2 = fopen("temp.txt", "wb");
    struct student st;

    for (size_t i = 0; i < n; i++)
    {
        get_student_by_pos(&st, f, i);
        fwrite(&st, sizeof(struct student), 1, f2);
    }
    fclose(f);
    fclose(f2);
    f = fopen(file_name, "wb");
    f2 = fopen("temp.txt", "rb");
    for (size_t i = 0; i < n; i++)
    {
        get_student_by_pos(&st, f2, i);
        fwrite(&st, sizeof(struct student), 1, f);
    }
    remove("temp.txt");
    fclose(f);
}

double student_average_all_lesson(FILE *f)
{
    double res = 0;
    int count_num;
    struct student st;
    size_t n = file_count_el(f);
    for (count_num = 0; count_num < (int)n; count_num++)
    {
        get_student_by_pos(&st, f, count_num);
        //fseek(f, sizeof(struct student) * count_num, SEEK_SET);
        res += average_assessments(st.assessments);
    }
    res /= count_num;
    return res;
}

size_t student_dell(FILE *f,size_t pos)
{
    fseek(f, (pos + 1) * sizeof(struct student), SEEK_SET);
    struct student st;
    pos++;
    for (; fread(&st, sizeof(struct student), 1, f) == 1; pos++)
    {
        file_swap(f, pos, pos - 1);
        fseek(f, (pos + 1) * sizeof(struct student), SEEK_SET);
    }
    return pos - 1;
}

void students_dell(char file_name[20])
{
    FILE *f = fopen(file_name, "r+b");
    double average = student_average_all_lesson(f);

    printf("%lf\n", average);
    struct student st;

    fseek(f, 0, SEEK_SET);
    size_t n = file_count_el(f);
    for (size_t i = 0; i < n; i++)
    {
        get_student_by_pos(&st, f, i);
        if (average_assessments(st.assessments) < average)
        {
            size_t file_new_len = student_dell(f, i);
            file_dell_last_el(file_name, file_new_len);
            fclose(f);
            //students_output(file_name);
           // printf("--------------\n");
            FILE *f = fopen(file_name, "r+b");
            fseek(f, i * sizeof(struct student), SEEK_SET);
            i--;
           // printf("ok: %s\n", a.name);
        }
            
    }
    fclose(f);
}

void student_sort(char file_name[FILE_NAME_LEN])
{
    FILE *f = fopen(file_name, "r+b");
    size_t n = file_count_el(f);
    for (size_t i = 1; i < n; i++)
        for (size_t j = 0; j < n - i; j++)
        {
            struct student st1;
            get_student_by_pos(&st1, f, j);

            struct student st2;
            get_student_by_pos(&st2, f, j + 1);
            if (strcoll(st1.surname, st2.surname) > 0)
                file_swap(f, j, j + 1);
            else 
                if (strcoll(st1.surname, st2.surname) == 0)
                    if (strcoll(st1.name, st2.name) > 0)
                        file_swap(f, j, j + 1);
        }
    
    fclose(f);
}

int substring_in_str(char s[], char subs[])
{
    if (strlen(subs) > strlen(s))
        return 0;
    size_t i;
    for (i = 0; s[i] != '\0' && subs[i] != '\0'; i++)
    {
        if (s[i] != subs[i])
            return 0;
    }
    return 1;
}

void student_find(char file_name[FILE_NAME_LEN], char subs[])
{
    
    FILE *f = fopen(file_name, "rb");
    FILE *f2 = fopen("tmp.bin", "wb");
    size_t n = file_count_el(f);
    for (size_t i = 0; i < n; i++)
    {
        struct student st;
        get_student_by_pos(&st, f, i);
        if (substring_in_str(st.surname, subs))
        {
            fwrite(&st, sizeof(struct student), 1, f2);
        }
            
    }
    fclose(f);
    fclose(f2);
}