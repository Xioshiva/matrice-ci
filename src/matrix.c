#include "matrix.h"

matrix matrix_create(int m, int n){
    matrix mat;
    return mat; 
}

void matrix_destroy(matrix *mat){

}

matrix matrix_create_from_array(int m, int n, double data[]){
    matrix mat;
    return mat; 
}

matrix matrix_clone(matrix mat){
    matrix newmat;
    return newmat;
}

void matrix_print(matrix mat){

}

int matrix_resize(matrix *mat, int m, int n){
    return 1;
}

bool matrix_is_approx_equal(matrix mat1, matrix mat2, double epsilon){
    return true;
}

bool matrix_is_equal(matrix mat1, matrix mat2){
    return true;
}

int matrix_add_in_place(matrix mat1, matrix mat2){
    return 1;
}

int matrix_sub_in_place(matrix mat1, matrix mat2){
    return 1;
}

int matrix_mult_in_place(matrix mat1, matrix mat2){
    return 1;
}

int matrix_add_scalar_in_place(matrix mat1, double n){
    return 1;
}

int matrix_mult_scalar_in_place(matrix mat1, double n){
    return 1;
}

int matrix_transpose_in_place(matrix mat){
    return 1;
}

matrix matrix_add(matrix mat1, matrix mat2){
    matrix mat;
    return mat;
}

matrix matrix_sub(matrix mat1, matrix mat2){
    matrix mat;
    return mat;
}

matrix matrix_mult(matrix mat1, matrix mat2){
    matrix mat;
    return mat;
}

matrix matrix_add_scalar(matrix mat, double n){
    matrix newmat;
    return newmat;
}

matrix matrix_mult_scalar(matrix mat, double n){
    matrix newmat;
    return newmat;
}

matrix matrix_transpose(matrix mat){
    matrix newmat;
    return newmat;
}