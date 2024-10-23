#include "check_mysort.h"
#include "check_arr.h"
#include "check_key.h"
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>


int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = check_arr_f();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    printf("failed1: %d\n", no_failed);

    s = check_key_f();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    printf("failed2: %d\n", no_failed);

    s = check_mysort_f();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    printf("failed3: %d\n", no_failed);
    return 0;
}