#include "filter.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

int filter_sharpen_in_place(matrix *mat){
    if(matrix_verrif(*mat) == 0)
        return 0;
    matrix matClone = matrix_clone(*mat);
    matrix_destroy(mat);
    *mat = filter_sharpen(matClone);
    matrix_destroy(&matClone);
    return 1;
}

int filter_blur_in_place(matrix *mat){
    if(matrix_verrif(*mat) == 0)
        return 0;
    matrix matClone = matrix_clone(*mat);
    matrix_destroy(mat);
    *mat = filter_blur(matClone);
    matrix_destroy(&matClone);
    return 1;
}

int filter_edge_enhance_in_place(matrix *mat){
    if(matrix_verrif(*mat) == 0)
        return 0;
    matrix matClone = matrix_clone(*mat);
    matrix_destroy(mat);
    *mat = filter_edge_enhance(matClone);
    matrix_destroy(&matClone);
    return 1;
}

int filter_edge_detect_in_place(matrix *mat){
    if(matrix_verrif(*mat) == 0)
        return 0;
    matrix matClone = matrix_clone(*mat);
    matrix_destroy(mat);
    *mat = filter_edge_detect(matClone);
    matrix_destroy(&matClone);
    return 1;
}

int filter_emboss_in_place(matrix *mat){
    if(matrix_verrif(*mat) == 0)
        return 0;
    matrix matClone = matrix_clone(*mat);
    matrix_destroy(mat);
    *mat = filter_emboss(matClone);
    matrix_destroy(&matClone);
    return 1;
}

matrix filter_sharpen(matrix mat){
    matrix res;
    if(matrix_verrif(mat) == 0){
        matrix_nulify(&res);
        return res;
    }
    res = matrix_clone(mat);
    double datakernel[] = {0.0, -1.0, 0.0,
                          -1.0, 5.0, -1.0,
                          0.0, -1.0, 0.0};
    matrix kernel = matrix_create_from_array(3, 3, datakernel);
    matrix_convolve_in_place(&res,kernel);
    matrix_clipper_in_place(res);
    matrix_destroy(&kernel);
    return res;
}

matrix filter_blur(matrix mat){
    matrix res;
    if(matrix_verrif(mat) == 0){
        matrix_nulify(&res);
        return res;
    }
    res = matrix_clone(mat);
    double datakernel[] = {1.0, 1.0, 1.0,
                          1.0, 1.0, 1.0,
                          1.0, 1.0, 1.0};
    matrix kernel = matrix_create_from_array(3, 3, datakernel);
    matrix_mult_scalar_in_place(kernel, 1.0 / 9.0);
    matrix_convolve_in_place(&res,kernel);
    matrix_clipper_in_place(res);
    matrix_destroy(&kernel);
    return res;
}

matrix filter_edge_enhance(matrix mat){
    matrix res;
    if(matrix_verrif(mat) == 0){
        matrix_nulify(&res);
        return res;
    }
    res = matrix_clone(mat);
    double datakernel[] = {0.0, 0.0, 0.0,
                          -1.0, 1.0, 0.0,
                          0.0, 0.0, 0.0};
    matrix kernel = matrix_create_from_array(3, 3, datakernel);
    matrix_convolve_in_place(&res,kernel);
    matrix_clipper_in_place(res);
    matrix_destroy(&kernel);
    return res;
}

matrix filter_edge_detect(matrix mat){
    matrix res;
    if(matrix_verrif(mat) == 0){
        matrix_nulify(&res);
        return res;
    }
    res = matrix_clone(mat);
    double datakernel[] = {0.0, 1.0, 0.0,
                          1.0, -4.0, 1.0,
                          0.0, 1.0, 0.0};
    matrix kernel = matrix_create_from_array(3, 3, datakernel);
    matrix_convolve_in_place(&res,kernel);
    matrix_clipper_in_place(res);
    matrix_destroy(&kernel);
    return res;
}

matrix filter_emboss(matrix mat){
    matrix res;
    if(matrix_verrif(mat) == 0){
        matrix_nulify(&res);
        return res;
    }
    res = matrix_clone(mat);
    double datakernel[] = {-2.0, -1.0, 0.0,
                          -1.0, 1.0, 1.0,
                          0.0, 1.0, 2.0};
    matrix kernel = matrix_create_from_array(3, 3, datakernel);
    matrix_convolve_in_place(&res,kernel);
    matrix_clipper_in_place(res);
    matrix_destroy(&kernel);
    return res;
}