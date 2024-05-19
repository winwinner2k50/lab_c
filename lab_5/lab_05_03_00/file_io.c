#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void file_gen(FILE *f, size_t n)
{
    srand(time(NULL)); 
    int size_int = sizeof(int);
    for (size_t i = 0; i < n; i++)
    {
        int el = rand() % 10;
        fwrite(&el, size_int, 1, f);
    }
}

void file_output_el(FILE *f)
{
    int size_int = sizeof(int);
    int el = 11;
    while (fread(&el, size_int, 1, f) == 1)
    {
       printf("%d ", el);
    }
    
}

int get_number_by_pos(FILE *f, size_t pos)
{
    fseek(f, pos * sizeof(int), SEEK_SET);
    printf("%zu|\n",ftell(f));
    int el;
    fread(&el, sizeof(int), 1, f);
    return el;
}

void put_number_by_pos(FILE *f, size_t pos, int num)
{
    fseek(f, sizeof(int) * pos, SEEK_SET);
    fwrite(&num, sizeof(num), 1, f);
}

void file_swap(FILE *f, size_t i, size_t j)
{
    int a = get_number_by_pos(f, i);
    put_number_by_pos(f, i, get_number_by_pos(f, j));
    put_number_by_pos(f, j, a);
}

void file_sort_el(FILE *f, size_t n)
{
    for (size_t i = 1; i < n; i++)
        for (size_t j = 0; j < n - i; j++)
            if (get_number_by_pos(f, j) > get_number_by_pos(f, j + 1))
                file_swap(f, j, j + 1);
}

