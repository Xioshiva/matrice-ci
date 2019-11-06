#include "test_matrix.h"
#include "test_pgm.h"
#include "test_geom.h"
#include <stdio.h>
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"

int main() {

    CU_pSuite matrix_suite = NULL;
    CU_pSuite pgm_suite = NULL;
    CU_pSuite geom_suite = NULL;

    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

    /* add a suite to the registry */
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
        (NULL == CU_add_test(matrix_suite, "test of matrix_normalize_in_place", test_matrix_normalize_in_place)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_add", test_matrix_add)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_sub", test_matrix_sub)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_mult", test_matrix_mult)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_add_scalar", test_matrix_add_scalar)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_mult_scalar", test_matrix_mult_scalar)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_transpose", test_matrix_transpose)) ||
        (NULL == CU_add_test(matrix_suite, "test of matrix_normalize", test_matrix_normalize)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* add a suite to the registry */
    pgm_suite = CU_add_suite("PGM suite", NULL, NULL);
    if (NULL == pgm_suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pgm_suite, "test of pgm_is_equal", test_pgm_is_equal)) ||
        (NULL == CU_add_test(pgm_suite, "test of pgm_is_approx_equal", test_pgm_is_approx_equal)) ||
        (NULL == CU_add_test(pgm_suite, "test of pgm_read", test_pgm_read)) ||
        (NULL == CU_add_test(pgm_suite, "test of pgm_write", test_pgm_write)) ||
        (NULL == CU_add_test(pgm_suite, "test of pgm_destroy", test_pgm_destroy)))
    {
        CU_cleanup_registry();
        return CU_get_error();        
    }

    /* add a suite to the registry */
    geom_suite = CU_add_suite("Geom suite", NULL, NULL);
    if (NULL == pgm_suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(geom_suite, "test of geom_vertical_axis_reflect_in_place", test_geom_vertical_axis_reflect_in_place)) ||
        (NULL == CU_add_test(geom_suite, "test of geom_horizontal_axis_reflect_in_place", test_geom_horizontal_axis_reflect_in_place)) ||
        (NULL == CU_add_test(geom_suite, "test of geom_central_reflect_in_place", test_geom_central_reflect_in_place)) ||
        (NULL == CU_add_test(geom_suite, "test of geom_rotate_in_place", test_geom_rotate_in_place)) ||
        (NULL == CU_add_test(geom_suite, "test of geom_photomaton_in_place", test_geom_photomaton_in_place)) ||
        (NULL == CU_add_test(geom_suite, "test of geom_vertical_axis_reflect", test_geom_vertical_axis_reflect)) ||
        (NULL == CU_add_test(geom_suite, "test of geom_horizontal_axis_reflect", test_geom_horizontal_axis_reflect)) ||
        (NULL == CU_add_test(geom_suite, "test of geom_central_reflect", test_geom_central_reflect)) ||
        (NULL == CU_add_test(geom_suite, "test of geom_rotate", test_geom_rotate)) ||
        (NULL == CU_add_test(geom_suite, "test of geom_photomaton", test_geom_photomaton)))
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