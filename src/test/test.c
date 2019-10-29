#include "test_matrix.h"
#include <stdio.h>
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"

int main() {

    CU_pSuite matrix_suite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

    /* add a suite to the registry */
    // matrix_suite = CU_add_suite("Matrix suite", setup, teardown);
    matrix_suite = CU_add_suite("Matrix suite", NULL, NULL);
    if (NULL == matrix_suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(matrix_suite, "test of matrix_create", test_matrix_create)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_destroy", test_matrix_destroy)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_create_from_array", test_matrix_create_from_array)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_clone", test_matrix_clone)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_resize", test_matrix_resize)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_is_approx_equal", test_matrix_is_approx_equal)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_is_equal", test_matrix_is_equal)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_add_in_place", test_matrix_add_in_place)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_sub_in_place", test_matrix_sub_in_place)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_mult_in_place", test_matrix_mult_in_place)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_add_scalar_in_place", test_matrix_add_scalar_in_place)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_mult_scalar_in_place", test_matrix_mult_scalar_in_place)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_transpose_in_place", test_matrix_transpose_in_place)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_add", test_matrix_add)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_sub", test_matrix_sub)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_mult", test_matrix_mult)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_add_scalar", test_matrix_add_scalar)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_mult_scalar", test_matrix_mult_scalar)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_transpose", test_matrix_transpose)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic (console output) and Automated (xml output) interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");

    CU_automated_run_tests();
   
    // return CU_get_error();
    return CU_get_number_of_tests_failed();
}