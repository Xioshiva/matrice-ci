#ifndef FILTER_H
#define FILTER_H

#include "matrix.h"

int filter_sharpen_in_place(matrix *mat);

int filter_blur_in_place(matrix *mat);

int filter_edge_enhance_in_place(matrix *mat);

int filter_edge_detect_in_place(matrix *mat);

int filter_emboss_in_place(matrix *mat);

matrix filter_sharpen(matrix mat);

matrix filter_blur(matrix mat);

matrix filter_edge_enhance(matrix mat);

matrix filter_edge_detect(matrix mat);

matrix filter_emboss(matrix mat);

#endif