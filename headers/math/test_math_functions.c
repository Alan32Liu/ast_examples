#include <check.h>  // Include the Check testing framework header.
#include "math_functions.h"  // Include the header file containing your functions.

// Define the test case for the 'add' function.
START_TEST(test_add) {
    int result = add(2, 3);
    ck_assert_int_eq(result, 5);  // Check if the result is as expected.
}
END_TEST

// Define a test suite that includes the 'test_add' test case.
Suite *math_functions_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Math Functions");  // Give your test suite a name.
    tc_core = tcase_create("Core");      // Create a test case.

    // Add your test cases to the test case.
    tcase_add_test(tc_core, test_add);

    // Add the test case to the suite.
    suite_add_tcase(s, tc_core);

    return s;
}