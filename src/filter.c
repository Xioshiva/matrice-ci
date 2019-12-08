#include "filter.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

int filter_sharpen_in_place(matrix *mat){
    if(mat->data != NULL){
    double datakernel[] = {0.0, -1.0, 0.0,
                          -1.0, 5.0, -1.0,
                          0.0, -1.0, 0.0};
    matrix kernel = matrix_create_from_array(3, 3, datakernel);
    matrix_convolve_in_place(mat,kernel);
    matrix_clipper_in_place(*mat);
    matrix_destroy(&kernel);
    // matrix_print(*mat);
    // matrix_print(kernel);
    return 1;
    }
}

int filter_blur_in_place(matrix *mat){
    return 0;
}

int filter_edge_enhance_in_place(matrix *mat){
    return 0;
}

int filter_edge_detect_in_place(matrix *mat){
    return 0;
}

int filter_emboss_in_place(matrix *mat){
    return 0;
}

matrix filter_sharpen(matrix mat){
    matrix res;
    return res;
}

matrix filter_blur(matrix mat){
    matrix res;
    return res;
}

matrix filter_edge_enhance(matrix mat){
    matrix res;
    return res;
}

matrix filter_edge_detect(matrix mat){
    matrix res;
    return res;
}

matrix filter_emboss(matrix mat){
    matrix res;
    return res;
}