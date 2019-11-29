#include "geom.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

int geom_vertical_axis_reflect_in_place(matrix *mat){
    if(mat->data == NULL)
        return 0;
    int milieu = 0;
    int k = 0;
    matrix myClone = matrix_create(mat->m, mat->n);
    if(mat->n % 2 == 0){
        milieu = mat->n/2;
        for (int i = 0; i < mat->m; i++)
        {
            for (int j = 0; j < milieu; j++)
            {
                printf("%d %d\n", mat->n - j - 1, j);
                myClone.data[i][mat->n - j - 1] = mat->data[i][j];   
            }
        }
        for (int i = 0; i < mat->m; i++)
        {
            for (int j = milieu; j < mat->n; j++)
            {
                printf("%d %d\n", milieu - k -1, j);
                myClone.data[i][milieu - k - 1] = mat->data[i][j];
                k++;
            }
            k=0;
        }
    }
    else{
        milieu = mat->n/2;
        for (int i = 0; i < mat->m; i++)
        {
            for (int j = 0; j < milieu; j++)
            {
                
                myClone.data[i][mat->n - j - 1] = mat->data[i][j];
            }
        }
        for (int i = 0; i < mat->m; i++)
        {
            for (int j = milieu; j < mat->n; j++)
            {
                myClone.data[i][milieu - k] = mat->data[i][j];
                k++;
            }
            k = 0;
        }
    
    }
    for (int i = 0; i < mat->m; i++)
    {
        for (int j = 0; j < mat->n; j++)
        {
            mat->data[i][j] = myClone.data[i][j];
        }
    }
    return 1;
}

int geom_horizontal_axis_reflect_in_place(matrix *mat){
    if(mat->data == NULL)
        return 0;
    int milieu = 0;
    int k = 0;
    matrix myClone = matrix_create(mat->m, mat->n);
    if(mat->m % 2 == 0){
        milieu = mat->m/2;
        for (int i = 0; i < milieu; i++)
        {
            for (int j = 0; j < mat->n; j++)
            {
                myClone.data[mat->m - i - 1][j] = mat->data[i][j];   
            }
        }
        for (int i = milieu; i < mat->m; i++)
        {
            for (int j = 0; j < mat->n; j++)
            {
                myClone.data[milieu - k - 1][milieu - k - 1] = mat->data[i][j];
            }
            k++;
        }
    }
    else{
        milieu = mat->m/2;
        for (int i = 0; i < milieu; i++)
        {
            for (int j = 0; j < mat->n; j++)
            {              
                myClone.data[mat->m - i - 1][j] = mat->data[i][j];
            }
        }
        for (int i = milieu; i < mat->m; i++)
        {
            for (int j = 0; j < mat->n; j++)
            {
                myClone.data[milieu - k][j] = mat->data[i][j];
            }
            k++;
        }
    
    }
    for (int i = 0; i < mat->m; i++)
    {
        for (int j = 0; j < mat->n; j++)
        {
            mat->data[i][j] = myClone.data[i][j];
        }
    }
    return 1;
}

int geom_central_reflect_in_place(matrix *mat){
    if(mat->data == NULL)
        return 0;
    geom_vertical_axis_reflect_in_place(mat);
    geom_horizontal_axis_reflect_in_place(mat);
    return 1;
}

int geom_rotate_in_place(matrix *mat, double angle, matrix center){
    return 0;
}

int geom_photomaton_in_place(matrix *mat){
    return 0;
}

int geom_translate_in_place(matrix *mat, matrix translation){
    return 0;
}

int geom_zoom_in_place(matrix *mat, matrix factors){
    return 0;
}

matrix geom_vertical_axis_reflect(matrix mat){
    matrix res;
    return res;
}

matrix geom_horizontal_axis_reflect(matrix mat){
    matrix res;
    return res;
}

matrix geom_central_reflect(matrix mat){
    matrix res;
    return res;
}

matrix geom_rotate(matrix mat, double angle, matrix center){
    matrix res;
    return res;
}

matrix geom_photomaton(matrix mat){
    matrix res;
    return res;
}

matrix geom_translate(matrix mat, matrix translation){
    matrix res;
    return res;
}

matrix geom_zoom(matrix mat, matrix factors){   
    matrix res;
    return res;
}