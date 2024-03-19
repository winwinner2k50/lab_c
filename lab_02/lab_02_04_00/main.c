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

void out_array(int array[], int len)
{
    for(int i = 0; i < len; i++)
        if(i + 1 != len)
            printf("%d ", array[i]);
        else
            printf("%d\n", array[i]);
}

void swap_elements_in_array(int array[], int element_first, int element_second)
{
    int num_first = array[element_first];
    array[element_first] = array[element_second];
    array[element_second] = num_first;
}

void sort_selection(int array[], int len)
{
    int swap_element;
    for(int i = 0; i < len; i++)
    {
        swap_element = i;
        for(int j = i + 1; j < len; j++)
        {
            if(array[j] < array[swap_element])
                swap_element = j;
        }
        swap_elements_in_array(array, swap_element, i);
    }
}



int main(void)
{
    int array[1000];
    int len;

    printf("Введите длину массива\n");
    int rm = scanf("%d", &len);

    if(rm != 1 || len <= 0)
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

    sort_selection(array, len);
    out_array(array, len);
}