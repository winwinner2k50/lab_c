#include <check.h>
#include <stdio.h>
#include "mysort.h"
#include "arr.h"

START_TEST(int1)
{
   
    int a[] = {3, 1, 2};
    int b[] = {1, 2, 3};
    size_t n = 3;
    mysort(a, sizeof(int), n, comparator_int);
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(a[i], b[i]);
}
END_TEST

START_TEST(int2)
{
   
    int a[] = {1};
    int b[] = {1};
    size_t n = 1;
    mysort(a, sizeof(int), n, comparator_int);
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(a[i], b[i]);
}
END_TEST

START_TEST(int3)
{
   
    int a[] = {-1, -2, 3, 0, 1, 100, 98, 99, 101, -100, 0, 2, 3, 5};
    int b[] = {-100, -2, -1, 0, 0, 1, 2, 3, 3, 5, 98, 99, 100, 101};
    size_t n = 14;
    
    mysort(a, sizeof(int), n, comparator_int);
    for (size_t i = 0; i < n; i++)
        ck_assert_int_eq(a[i], b[i]);
}
END_TEST

START_TEST(double1)
{
    double a[] = {1.1};
    double b[] = {1.1};
    size_t n = 1;
    mysort(a, sizeof(double), n, comparator_double);
    for (size_t i = 0; i < n; i++)
        ck_assert_double_eq_tol(a[i], b[i], 1e-8);
}
END_TEST

START_TEST(double2)
{
    double a[] = {9.1, -1.1, 5.1, 0.0, 0.2, 0.3, 0.1, -0.2, -2.3, -0.3};
    double b[] = {-2.3, -1.1, -0.3, -0.2, 0.0, 0.1, 0.2, 0.3, 5.1, 9.1};
    size_t n = 10;
    mysort(a, sizeof(double), n, comparator_double);
    for (size_t i = 0; i < n; i++)
        ck_assert_double_eq_tol(a[i], b[i], 1e-8);
}
END_TEST

START_TEST(double3)
{
    double a[] = {1, 2, 3};
    double b[] = {1, 2, 3};
    size_t n = 3;
    mysort(a, sizeof(double), n, comparator_double);
    for (size_t i = 0; i < n; i++)
        ck_assert_double_eq_tol(a[i], b[i], 1e-8);
}
END_TEST

START_TEST(double4)
{
    double a[] = {3, 2, 1};
    double b[] = {1, 2, 3};
    size_t n = 3;
    mysort(a, sizeof(double), n, comparator_double);
    
    for (size_t i = 0; i < n; i++)
        ck_assert_double_eq_tol(a[i], b[i], 1e-8);
}
END_TEST

Suite* check_mysort_f(void)
{
    Suite *s;
    TCase *tc_int;
    TCase *tc_double;

    s = suite_create("check_mysort");
    
    tc_int = tcase_create("int");

    tcase_add_test(tc_int, int1);
    tcase_add_test(tc_int, int2);
    tcase_add_test(tc_int, int3);

    suite_add_tcase(s, tc_int);

    tc_double = tcase_create("double");
    
    tcase_add_test(tc_double, double1);
    tcase_add_test(tc_double, double2);
    tcase_add_test(tc_double, double3);
    tcase_add_test(tc_double, double4);

    suite_add_tcase(s, tc_double);

    return s;
}