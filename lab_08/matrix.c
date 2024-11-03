#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "matrix.h"


int num_input_int(char *pos, FILE *f)
{
    return fscanf(f, "%d", (int*)(pos));
}

void num_output_int(char *pos)
{
    printf("%d", (int)(*pos));
}

int matrix_from_file(char ***lins, size_t *n, size_t *m, size_t tips_size, char file_name[], int (f_input)(char*, FILE*))
{
    FILE *f = fopen(file_name, "r");

    if (f == NULL)
        return ERROR_FILE_INPUT_NULL;
    
    (*n) = 0;
    (*m) = 0;

    if(fscanf(f, "%zu%zu", n, m) != 2)
    {
        fclose(f);
        return ERROR_READ_FIRST_LINE;
    }
    
    (*lins) = malloc((*n) * sizeof(int*));
    
    for (size_t i = 0; i < *n; i++)
    {
        (*lins)[i] = malloc((*m) * tips_size);
        for(size_t j = 0; j < *m; j++)
            f_input(((*lins)[i] + j * tips_size), f);
            
    }

   
    fclose(f);
    return 0;
}

int matrix_output(char **lins, size_t n, size_t m, size_t tips_size)
{
    for (size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            num_output_int(((lins)[i] + j * tips_size));
            printf(" ");
        }
          
        printf("\n");
    }
}

int matrix_clear(char ***lins, size_t n)
{
    for (size_t i = 0; i < n; i++)
        free((*lins)[i]);
    free(*lins);
    return 0;
}