#define _DEFAULT_SOURCE

#include <stdlib.h>
#include "test_geom.h"
#include "../geom.h"
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"
#include <math.h>

void test_geom_vertical_axis_reflect_in_place(){
    double datamat[] = {0.0,  1.0,  2.0,  3.0,  4.0,
                        5.0,  6.0,  7.0,  8.0,  9.0,
                        10.0, 11.0, 12.0, 13.0, 14.0,
                        15.0, 16.0, 17.0, 18.0, 19.0,
                        20.0, 21.0, 22.0, 23.0, 24.0};
    double datareflected[] = {4.0,  3.0,  2.0,  1.0,  0.0,
                              9.0,  8.0,  7.0,  6.0,  5.0,
                              14.0, 13.0, 12.0, 11.0, 10.0,
                              19.0, 18.0, 17.0, 16.0, 15.0,
                              24.0, 23.0, 22.0, 21.0, 20.0};
    matrix mat, reflected;
    // nullness
    mat.data = NULL;
    CU_ASSERT(geom_vertical_axis_reflect_in_place(&mat)==0);
    // values
    mat = matrix_create_from_array(5, 5, datamat);
    reflected = matrix_create_from_array(5, 5, datareflected);
    CU_ASSERT(geom_vertical_axis_reflect_in_place(&mat)>0);
    CU_ASSERT(matrix_is_equal(mat, reflected));
    matrix_destroy(&mat);
    matrix_destroy(&reflected);
}

void test_geom_horizontal_axis_reflect_in_place(){
    double datamat[] = {0.0,  1.0,  2.0,  3.0,  4.0,
                        5.0,  6.0,  7.0,  8.0,  9.0,
                        10.0, 11.0, 12.0, 13.0, 14.0,
                        15.0, 16.0, 17.0, 18.0, 19.0,
                        20.0, 21.0, 22.0, 23.0, 24.0};
    double datareflected[] = {20.0, 21.0, 22.0, 23.0, 24.0,
                              15.0, 16.0, 17.0, 18.0, 19.0,
                              10.0, 11.0, 12.0, 13.0, 14.0,
                              5.0,  6.0,  7.0,  8.0,  9.0,
                              0.0,  1.0,  2.0,  3.0,  4.0};
    matrix mat, reflected;
    // nullness
    mat.data = NULL;
    CU_ASSERT(geom_horizontal_axis_reflect_in_place(&mat)==0);
    // values
    mat = matrix_create_from_array(5, 5, datamat);
    reflected = matrix_create_from_array(5, 5, datareflected);
    CU_ASSERT(geom_horizontal_axis_reflect_in_place(&mat)>0);
    CU_ASSERT(matrix_is_equal(mat, reflected));
    matrix_destroy(&mat);
    matrix_destroy(&reflected);
}

void test_geom_central_reflect_in_place(){
    double datamat[] = {0.0,  1.0,  2.0,  3.0,  4.0,
                        5.0,  6.0,  7.0,  8.0,  9.0,
                        10.0, 11.0, 12.0, 13.0, 14.0,
                        15.0, 16.0, 17.0, 18.0, 19.0,
                        20.0, 21.0, 22.0, 23.0, 24.0};
    double datareflected[] = {24.0, 23.0, 22.0, 21.0, 20.0,
                              19.0, 18.0, 17.0, 16.0, 15.0,
                              14.0, 13.0, 12.0, 11.0, 10.0,
                              9.0,  8.0,  7.0,  6.0,  5.0,
                              4.0,  3.0,  2.0,  1.0,  0.0};
    matrix mat, reflected;
    // nullness
    mat.data = NULL;
    CU_ASSERT(geom_central_reflect_in_place(&mat)==0);
    // values
    mat = matrix_create_from_array(5, 5, datamat);
    reflected = matrix_create_from_array(5, 5, datareflected);
    CU_ASSERT(geom_central_reflect_in_place(&mat)>0);
    CU_ASSERT(matrix_is_equal(mat, reflected));
    matrix_destroy(&mat);
    matrix_destroy(&reflected);
}

void test_geom_rotate_in_place(){
    double datamat[] = {0.0,  1.0,  2.0,  3.0,  4.0,
                        5.0,  6.0,  7.0,  8.0,  9.0,
                        10.0, 11.0, 12.0, 13.0, 14.0,
                        15.0, 16.0, 17.0, 18.0, 19.0,
                        20.0, 21.0, 22.0, 23.0, 24.0};
    double datarotated[] = {20.0, 15.0, 10.0, 5.0, 0.0,
                            21.0, 16.0, 11.0, 6.0, 1.0,
                            22.0, 17.0, 12.0, 7.0, 2.0,
                            23.0, 18.0, 13.0, 8.0, 3.0,
                            24.0, 19.0, 14.0, 9.0, 4.0};
    double datacenter[] = {2, 2};
    matrix mat, rotated, center;
    double angle = M_PI/2.0;
    // nullness
    mat.data = NULL;
    center.data = NULL;
    CU_ASSERT(geom_rotate_in_place(&mat, angle, center)==0);
    // values
    mat = matrix_create_from_array(5, 5, datamat);
    rotated = matrix_create_from_array(5, 5, datarotated);
    center = matrix_create_from_array(1, 2, datacenter);
    CU_ASSERT(geom_rotate_in_place(&mat, angle, center)>0);
    CU_ASSERT(matrix_is_equal(mat, rotated));
    matrix_destroy(&mat);
    matrix_destroy(&rotated);
    matrix_destroy(&center);
}

void test_geom_photomaton_in_place(){
    double datamat[] = {11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0,
                        21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0,
                        31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0,
                        41.0, 42.0, 43.0, 44.0, 45.0, 46.0, 47.0, 48.0,
                        51.0, 52.0, 53.0, 54.0, 55.0, 56.0, 57.0, 58.0,
                        61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0, 68.0,
                        71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0,
                        81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0};
    double dataphotomat[] = {11.0, 13.0, 15.0, 17.0, 12.0, 14.0, 16.0, 18.0,
                             31.0, 33.0, 35.0, 37.0, 32.0, 34.0, 36.0, 38.0,
                             51.0, 53.0, 55.0, 57.0, 52.0, 54.0, 56.0, 58.0,
                             71.0, 73.0, 75.0, 77.0, 72.0, 74.0, 76.0, 78.0,
                             21.0, 23.0, 25.0, 27.0, 22.0, 24.0, 26.0, 28.0,
                             41.0, 43.0, 45.0, 47.0, 42.0, 44.0, 46.0, 48.0,
                             61.0, 63.0, 65.0, 67.0, 62.0, 64.0, 66.0, 68.0,
                             81.0, 83.0, 85.0, 87.0, 82.0, 84.0, 86.0, 88.0};
    matrix mat, photomat;
    photomat = matrix_create_from_array(8, 8, dataphotomat);
    // nullness
    mat.data = NULL;
    CU_ASSERT(geom_photomaton_in_place(&mat)==0);
    // values
    mat = matrix_create_from_array(8, 8, datamat);
    CU_ASSERT(geom_photomaton_in_place(&mat)>0);
    CU_ASSERT(matrix_is_equal(mat, photomat));
    matrix_destroy(&mat);
    matrix_destroy(&photomat);
}

void test_geom_vertical_axis_reflect(){
    double datamat[] = {0.0,  1.0,  2.0,  3.0,  4.0,
                        5.0,  6.0,  7.0,  8.0,  9.0,
                        10.0, 11.0, 12.0, 13.0, 14.0,
                        15.0, 16.0, 17.0, 18.0, 19.0,
                        20.0, 21.0, 22.0, 23.0, 24.0};
    double datareflected[] = {4.0,  3.0,  2.0,  1.0,  0.0,
                              9.0,  8.0,  7.0,  6.0,  5.0,
                              14.0, 13.0, 12.0, 11.0, 10.0,
                              19.0, 18.0, 17.0, 16.0, 15.0,
                              24.0, 23.0, 22.0, 21.0, 20.0};
    matrix mat, reflected, res;
    // nullness
    mat.data = NULL;
    res = geom_vertical_axis_reflect(mat);
    CU_ASSERT(res.data==NULL);
    // values
    mat = matrix_create_from_array(5, 5, datamat);
    reflected = matrix_create_from_array(5, 5, datareflected);
    CU_ASSERT(!matrix_is_equal(res, reflected));
    res = geom_vertical_axis_reflect(mat);
    CU_ASSERT(matrix_is_equal(res, reflected));
    matrix_destroy(&mat);
    matrix_destroy(&reflected);
    matrix_destroy(&res);
}

void test_geom_horizontal_axis_reflect(){
    double datamat[] = {0.0,  1.0,  2.0,  3.0,  4.0,
                        5.0,  6.0,  7.0,  8.0,  9.0,
                        10.0, 11.0, 12.0, 13.0, 14.0,
                        15.0, 16.0, 17.0, 18.0, 19.0,
                        20.0, 21.0, 22.0, 23.0, 24.0};
    double datareflected[] = {20.0, 21.0, 22.0, 23.0, 24.0,
                              15.0, 16.0, 17.0, 18.0, 19.0,
                              10.0, 11.0, 12.0, 13.0, 14.0,
                              5.0,  6.0,  7.0,  8.0,  9.0,
                              0.0,  1.0,  2.0,  3.0,  4.0};
    matrix mat, reflected, res;
    // nullness
    mat.data = NULL;
    res = geom_horizontal_axis_reflect(mat);
    CU_ASSERT(res.data==NULL);
    // values
    mat = matrix_create_from_array(5, 5, datamat);
    reflected = matrix_create_from_array(5, 5, datareflected);
    CU_ASSERT(!matrix_is_equal(res, reflected));
    res = geom_horizontal_axis_reflect(mat);
    CU_ASSERT(matrix_is_equal(res, reflected));
    matrix_destroy(&mat);
    matrix_destroy(&reflected);
    matrix_destroy(&res);
}

void test_geom_central_reflect(){
    double datamat[] = {0.0,  1.0,  2.0,  3.0,  4.0,
                        5.0,  6.0,  7.0,  8.0,  9.0,
                        10.0, 11.0, 12.0, 13.0, 14.0,
                        15.0, 16.0, 17.0, 18.0, 19.0,
                        20.0, 21.0, 22.0, 23.0, 24.0};
    double datareflected[] = {24.0, 23.0, 22.0, 21.0, 20.0,
                              19.0, 18.0, 17.0, 16.0, 15.0,
                              14.0, 13.0, 12.0, 11.0, 10.0,
                              9.0,  8.0,  7.0,  6.0,  5.0,
                              4.0,  3.0,  2.0,  1.0,  0.0};
    matrix mat, reflected, res;
    // nullness
    mat.data = NULL;
    res = geom_central_reflect(mat);
    CU_ASSERT(res.data==NULL);
    // values
    mat = matrix_create_from_array(5, 5, datamat);
    reflected = matrix_create_from_array(5, 5, datareflected);
    CU_ASSERT(!matrix_is_equal(res, reflected));
    res = geom_central_reflect(mat);
    CU_ASSERT(matrix_is_equal(res, reflected));
    matrix_destroy(&mat);
    matrix_destroy(&reflected);
    matrix_destroy(&res);
}

void test_geom_rotate(){
    double datamat[] = {0.0,  1.0,  2.0,  3.0,  4.0,
                        5.0,  6.0,  7.0,  8.0,  9.0,
                        10.0, 11.0, 12.0, 13.0, 14.0,
                        15.0, 16.0, 17.0, 18.0, 19.0,
                        20.0, 21.0, 22.0, 23.0, 24.0};
    double datarotated[] = {20.0, 15.0, 10.0, 5.0, 0.0,
                            21.0, 16.0, 11.0, 6.0, 1.0,
                            22.0, 17.0, 12.0, 7.0, 2.0,
                            23.0, 18.0, 13.0, 8.0, 3.0,
                            24.0, 19.0, 14.0, 9.0, 4.0};
    double datacenter[] = {2, 2};
    matrix mat, rotated, center;
    double angle = M_PI/2.0;
    // nullness
    mat.data = NULL;
    center.data = NULL;
    matrix res = geom_rotate(mat, angle, center);
    CU_ASSERT(res.data==NULL);
    // values
    mat = matrix_create_from_array(5, 5, datamat);
    rotated = matrix_create_from_array(5, 5, datarotated);
    center = matrix_create_from_array(1, 2, datacenter);
    CU_ASSERT(!matrix_is_equal(res, rotated));
    res = geom_rotate(mat, angle, center);
    CU_ASSERT(matrix_is_equal(res, rotated));
    matrix_destroy(&mat);
    matrix_destroy(&rotated);
    matrix_destroy(&center);
    matrix_destroy(&res);
}

void test_geom_photomaton(){
    double datamat[] = {11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0,
                        21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0,
                        31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0,
                        41.0, 42.0, 43.0, 44.0, 45.0, 46.0, 47.0, 48.0,
                        51.0, 52.0, 53.0, 54.0, 55.0, 56.0, 57.0, 58.0,
                        61.0, 62.0, 63.0, 64.0, 65.0, 66.0, 67.0, 68.0,
                        71.0, 72.0, 73.0, 74.0, 75.0, 76.0, 77.0, 78.0,
                        81.0, 82.0, 83.0, 84.0, 85.0, 86.0, 87.0, 88.0};
    double dataphotomat[] = {11.0, 13.0, 15.0, 17.0, 12.0, 14.0, 16.0, 18.0,
                             31.0, 33.0, 35.0, 37.0, 32.0, 34.0, 36.0, 38.0,
                             51.0, 53.0, 55.0, 57.0, 52.0, 54.0, 56.0, 58.0,
                             71.0, 73.0, 75.0, 77.0, 72.0, 74.0, 76.0, 78.0,
                             21.0, 23.0, 25.0, 27.0, 22.0, 24.0, 26.0, 28.0,
                             41.0, 43.0, 45.0, 47.0, 42.0, 44.0, 46.0, 48.0,
                             61.0, 63.0, 65.0, 67.0, 62.0, 64.0, 66.0, 68.0,
                             81.0, 83.0, 85.0, 87.0, 82.0, 84.0, 86.0, 88.0};
    matrix mat, photomat;
    photomat = matrix_create_from_array(8, 8, dataphotomat);
    // nullness
    mat.data = NULL;
    matrix res = geom_photomaton(mat);
    CU_ASSERT(res.data==NULL);
    // values
    mat = matrix_create_from_array(8, 8, datamat);
    CU_ASSERT(!matrix_is_equal(res, photomat));
    res = geom_photomaton(mat);
    CU_ASSERT(matrix_is_equal(res, photomat));
    matrix_destroy(&mat);
    matrix_destroy(&photomat);
    matrix_destroy(&res);
}