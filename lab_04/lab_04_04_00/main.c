#include <stdio.h>
#include <string.h>
#include "str_io.h"

int main(void)
{
    char s[LEN];
    size_t n;

    char nums[LEN][LEN];
    size_t len_num;

    fgets(s, LEN, stdin);
    n = strlen(s);
    
    len_num = count_nums(nums, s, n);
    if (nums_is_ip(nums, len_num) == 0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}