#include <stdio.h>

int scanf_array(int len, int *array)
{
    for(int i = 0; i < len; i++)
        if(scanf("%d", &array[i]) != 1)
            return 1;
    return 0;
}

void out_array(int len, int *array)
{
    for(int i = 0; i < len; i++)
        printf("%d ", array[i]);
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
    int array[10], array_new[20];
    int len, len_new_array;
    double average_array;
    printf("Введите длину массива\n");
    scanf("%d", &len);

    if(len <= 0)
    {
        printf("Ошибка ввода длины массива\n");
        return 1;
    }

    printf("Введите элементы массива\n");

    if(scanf_array(len, array))
    {
        printf("Ошибка ввода элементов\n");
        return 2;
    }
    average_array = average(len, array);

    len_new_array = make_new_array(average_array, len, array, array_new);

    out_array(len_new_array, array_new);
}