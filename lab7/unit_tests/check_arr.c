#include <check.h>
#include <stdio.h>
#include "arr.h"

START_TEST(neg1)
{
    char file_name[] = "unit_test_file_arr/neg1.txt";
    int *a = NULL, *a_end = NULL;
    int res = arr_gen(&a, &a_end, file_name);
    ck_assert_int_eq(res, ERROR_NUMS_COUNT);
}
END_TEST

START_TEST(neg2)
{
    char file_name[] = "unit_test_file_arr/neg2.txt";
    int *a = NULL, *a_end = NULL;
    int res = arr_gen(&a, &a_end, file_name);
    ck_assert_int_eq(res, ERROR_NOT_END_FILE);
}
END_TEST

START_TEST(pos1)
{
    char file_name[] = "unit_test_file_arr/pos1.txt";
    int *a = NULL, *a_end = NULL;
    int b[] = {1, 2, 3};
    int res = arr_gen(&a, &a_end, file_name);
    ck_assert_int_eq(res, 0);
    int *el_a = a;
    int *el_b = b;
    while (el_a < a || el_b < b)
    {
        ck_assert_int_eq(*el_a, *el_b);
        el_a++;
        el_b++;
    }
        
}
END_TEST

Suite* check_arr_f(void)
{
    Suite *s;
    TCase *tc_pos;
    TCase *tc_neg;

    s = suite_create("check_arr");
    
    tc_pos = tcase_create("pos");

    tcase_add_test(tc_pos, pos1);

    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("neg");
    
    tcase_add_test(tc_neg, neg1);
    tcase_add_test(tc_neg, neg2);

    suite_add_tcase(s, tc_neg);

    return s;
}