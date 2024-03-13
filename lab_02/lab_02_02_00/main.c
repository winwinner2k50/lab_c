#include <stdio.h>

int scanf_array(int array[], int len)
{
    int res = 0;
    for(int i = 0; i < len; i++)
        if(scanf("%d", &array[i]) != 1)
            res = 1;

    return res;
}

void out_array(int array[], int len)
{
    for(int i = 0; i < len; i++)
        if(i + 1 != len)
            printf("%d ", array[i]);
        else
            printf("%d\n", array[i]);
}

double average(int len, int *array)
{
    int sum_num = 0;
    int count_num = 0;
    double average_num_res = 0;
    for (int i = 0; i < len; i++)
    {
        sum_num += array[i];
        count_num++;
    }

    if (count_num != 0)
        average_num_res = (double) sum_num / count_num;

    return average_num_res;
}

int make_new_array(double average_array, int len, int *array, int *array_new)
{
    int len_new = len;
    for(int i = 0; i < len; i++)
    {
        array_new[i] = array[i];
        if(array[i] > average_array)
        {
            array_new[len_new] = array[i];
            len_new++;
        }
    }

    return len_new;
}

int main(void)
{
    int array[1000], array_new[2000];
    int len, len_new_array;
    double average_array;
   printf("Введите длину массива\n");
    int rm = scanf("%d", &len);

    if(rm != 1 || len <= 0)
    {
        printf("Ошибка ввода длины массива\n");
        return 1;
    }

    printf("Введите элементы массива\n");

    if(scanf_array(array, len))
    {
        printf("Ошибка ввода элементов\n");
        return 2;
    }
    average_array = average(array, len);

    len_new_array = make_new_array(average_array, len, array, array_new);

    out_array(array_new, len_new_array);
}