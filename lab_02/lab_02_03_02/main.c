#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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

int is_palindrome(int num)
{
    num = abs(num);

    int res = 1;
    int num_array_reverse[100], num_len = 0;

    while (num > 0)
    {
        num_len++;
        num_array_reverse[num_len - 1] = num % 10;
        num /= 10;
    }

    for (int i = 0; i< num_len / 2; i++)
    {
        if(num_array_reverse[i] != num_array_reverse[num_len - 1 - i])
            res = 0;
    }

    return res;
}

int try_remove_palindrome(int array[], int len_old, int *len_new)
{
    if(array == NULL)
        return 1;

    *len_new = 0;

    for(int i = 0; i < len_old; i++)
    {
       // printf("%d %d\n", array[i], is_palindrome(array[i]));
        if(is_palindrome(array[i]) != 1)
        {
            (*len_new)++;
            array[*len_new - 1] = array[i];
        }
    }

    if (len_new == 0)
        return 2;
    else
        return 0;
}

int main(void)
{
    int array[1000];
    int len, len_new;
    int rm;

    //printf("%d\n", is_palindrome(5))

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
    rm = try_remove_palindrome(array, len, &len_new);
    if(rm == 0)
        output_array(array, len_new);
    else
    {
        if(rm == 1)
        {
            printf("Ошибка при удалении");
            return 3;
        }
        else
        {
            printf("Весь массив был удалён");
            return 4;
        }         
    }
        
    return 0;
}