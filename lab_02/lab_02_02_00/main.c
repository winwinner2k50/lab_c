#include <stdio.h>

int input_array(int array[], int len)
{
    int res = 0;

    if (len <= 0)
        res = 1;
    
    for (int i = 0; i < len; i++)
        if(scanf("%d", &array[i]) != 1)
            res = 1;

    return res;
}

void output_array(int array[], int len)
{
    for(int i = 0; i < len; i++)
        printf("%d ", array[i]);
        
    printf("\n");
}

int find_average(int array[], int len, double *average)
{
    if (array == NULL)
        return 1;
    
    int sum_num = 0;
    int count_num = 0;
    for (int i = 0; i < len; i++)
    {
        sum_num += array[i];
        count_num++;
    }

    if (count_num != 0)
        *average = (double) sum_num / count_num;
    else
        return 2;

    return 0;
}

int try_gen_new_array(int array_old[], int array_new[], int len_old, int *len_new)
{
    double average;

    if(array_old == NULL)
        return 1;

    if (find_average(array_old, len_old, &average) == 0)
    {
        *len_new = len_old;
        for(int i = 0; i < len_old; i++)
        {
            array_new[i] = array_old[i];
            if(array_old[i] > average)
            {
                (*len_new)++;
                array_new[*len_new - 1] = array_old[i];
            }
        }
    }
    else
        return 2;
        

    return 0;
}

int main(void)
{
    int array[1000], array_new[2000];

    int len, len_new;

    printf("Введите длину массива\n");

    if(scanf("%d", &len) != 1 || len <= 0)
    {
        printf("Ошибка ввода длины массива\n");
        return 1;
    }

    printf("Введите элементы массива\n");

    if(input_array(array, len))
    {
        printf("Ошибка ввода элементов\n");
        return 2;
    }


    if(try_gen_new_array(array, array_new, len, &len_new) == 0)
        output_array(array_new, len_new);
    else
    {
        printf("Ошибка при генираци нового массива");
        return 3;
    }
        
    return 0;
}