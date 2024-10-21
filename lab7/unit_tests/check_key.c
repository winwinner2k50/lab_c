#include <check.h>
#include <stdio.h>
#include "key.h"
#include "arr.h"

START_TEST(neg1)
{
    size_t n = 2;
    int a[] = {3, -1};
    int *b = NULL, *b_end = NULL;

    int res = key(a, a + n, &b, &b_end);

    ck_assert_int_eq(res, ERROR_NOT_DATA);

}     
END_TEST


START_TEST(pos1)
{
    size_t n = 3;
    int a[] = {3, 1 -1};
    int *b = NULL, *b_end = NULL;

    int res_arr[] = {1};
    int m = 1;
    
    int res = key(a, a + n, &b, &b_end);

    ck_assert_int_eq(res, 0);

    ck_assert_int_eq(b_end - b, m);

    int *el = b;

    int i = 0;
    while (el < b_end)
    {
        ck_assert_int_eq(*el, res_arr[i]);
        el++;
        i++;
    }
    ck_assert_int_eq(m, i);
}     
END_TEST

START_TEST(pos2)
{
    size_t n = 15;
    int a[] = {-1, -2, -3, -4, 1, 2, 3, 4, 4, 0, 4, 4, -4, -4};
    int *b = NULL, *b_end = NULL;

    int res_arr[] = {1, 2, 3};
    int m = 3;
    
    int res = key(a, a + n, &b, &b_end);

    arr_output_int(b, b_end);

    ck_assert_int_eq(res, 0);

    ck_assert_int_eq(b_end - b, m);

    int *el = b;

    int i = 0;
    while (el < b_end)
    {
        ck_assert_int_eq(*el, res_arr[i]);
        el++;
        i++;
    }
    ck_assert_int_eq(m, i);
}     
END_TEST


Suite* check_key_f(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("check_key");
    
    tc_pos = tcase_create("pos");

    tcase_add_test(tc_pos, pos1);
    tcase_add_test(tc_pos, pos2);

    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("neg");
    
    tcase_add_test(tc_neg, neg1);
    suite_add_tcase(s, tc_neg);

    return s;
}