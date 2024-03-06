#include <stdio.h>

int scanf_array(int len, int *array)
{
    for(int i = 0; i < len; i++)
        if(scanf("%d", &array[i]) != 1)
            return 1;
    return 0;
}

double average_neg_number(int len, int *array)
{
    int sum_neg_number = 0;
    int count_neg_number = 0;
    double average_neg_number_res = 0;
    for (int i = 0; i < len; i++)
    {
        if (array[i] < 0)
        {
            sum_neg_number += array[i];
            count_neg_number++;
        }
    }

    if (count_neg_number != 0)
        average_neg_number_res = (double) sum_neg_number / count_neg_number;

    return average_neg_number_res;
}

int main(void)
{
    int array[10];
    int len;
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

    printf("Среднее арефметическое отрицательных чисел равно: %lf\n", average_neg_number(len, array));

    return 0;
}
