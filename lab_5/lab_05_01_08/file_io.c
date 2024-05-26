#include <stdio.h>

int process(FILE *f, int *len_loc_max)
{
    (*len_loc_max) = 0;
    int res = 1;
    int left, loc_max, right;
    if (fscanf(f, "%d%d", &left, &loc_max) != 2)
        return res;
    int len = -1;
    while(fscanf(f, "%d", &right) == 1)
    {
        if (left < loc_max && right < loc_max)
        {
            if (len != -1)
            {
                res = 0;
                if (*len_loc_max < len)
                    (*len_loc_max) = len;
            }
            len = 0;
        }
        else
        {
            if (len != -1)
                len++;
        }
        left = loc_max;
        loc_max = right;
    }
    return res;
}

