#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "matrix_input_output.h"

int num_input_int(void *pos)
{
    return scanf("%d", (int*)(pos));
}

void num_output_int(void *pos)
{
    printf("%d", *((int*)pos));
}

// int num_input_from_file_int(void *pos, FILE *f)
// {
//     return fscanf(f, "%d", (int*)(pos));
// }

//double

int num_input_double(void *pos)
{
    return scanf("%lf", (double*)(pos));
}

void num_output_double(void *pos)
{
    printf("%lf", *((double*)pos));
}

// int num_input_from_file_double(void *pos, FILE *f)
// {
//     double a;
//     fscanf(f, "%lf", &a);
//     *(double*)(pos) = a;
//     return 0;
// }




// int matrix_from_file(char ***lins, size_t *n, size_t *m, size_t tips_size, char file_name[], int (f_input)(char*, FILE*))
// {
//     FILE *f = fopen(file_name, "r");

//     if (f == NULL)
//         return ERROR_FILE_INPUT_NULL;
    
//     (*n) = 0;
//     (*m) = 0;

//     if(fscanf(f, "%zu%zu", n, m) != 2)
//     {
//         fclose(f);
//         return ERROR_READ_FIRST_LINE;
//     }
    
//     (*lins) = malloc((*n) * sizeof(char*));
    
//     for (size_t i = 0; i < *n; i++)
//     {
//         (*lins)[i] = malloc((*m) * tips_size);
        
//         for(size_t j = 0; j < *m; j++)
//             f_input(((*lins)[i] + j * tips_size), f);
//     }


   
//     fclose(f);
//     return 0;
// }




int matrix_input(void ***lins, size_t n, size_t m, size_t type_size, int (f_input)(void*))
{
    (*lins) = malloc(n * sizeof(char*));
    
    for (size_t i = 0; i < n; i++)
    {
        (*lins)[i] = malloc(m * type_size);
        
        for(size_t j = 0; j < m; j++)
            f_input(((char*)(*lins)[i] + j * type_size));
    }
    return 0;
}


void matrix_output(void **lins, size_t n, size_t m, size_t type_size, void (f_output)(void*))
{
    for (size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < m; j++)
        {
            f_output(((char*)(lins)[i] + j * type_size));
            printf(" ");
        }

        printf("\n");
    }
}

