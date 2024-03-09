#include <stdio.h>

int scanf_array(int array[], int len)
{
    int res = 0;
    for(int i = 0; i < len; i++)
        if(scanf("%d", &array[i]) != 1)
            res = 1;

    return res;
}

double average_neg_num(int array[], int len)
{
    int sum_neg_num = 0;
    int count_neg_num = 0;
    double average_neg_num_res = 0;
    for (int i = 0; i < len; i++)
    {
        if (array[i] < 0)
        {
            sum_neg_num += array[i];
            count_neg_num++;
        }
    }

    if (count_neg_num != 0)
        average_neg_num_res = (double) sum_neg_num / count_neg_num;

    return average_neg_num_res;
}

int main(void)
{
    int array[1000];
    int len;
    printf("Введите длину массива\n");
    scanf("%d", &len);

    if(len <= 0)
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

    printf("Среднее арефметическое отрицательных чисел равно: %lf\n", average_neg_num(array, len));

    return 0;
}
