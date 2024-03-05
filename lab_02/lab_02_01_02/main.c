#include <stdio.h>

int scanf_array(int len, int *array)
{
    for(int i = 0; i < len; i++)
        if(!scanf("%d", &array[i]))
            return 1;
    return 0;
}

double average(int len, int *array)
{
    double average_res = 0;
    int count_minus_number = 0; 
    for (int i = 0; i < len; i++)
    {
        if (array[i] < 0)
        {
            average_res += array[i];
            count_minus_number++;
        }
    }
    if (count_minus_number != 0)
        return average_res / count_minus_number;
    else
        return 0;
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

    printf("Среднее арефметическое отрицательных чисел равно: %lf\n", average(len, array));

    return 0;
}
