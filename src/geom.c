#include "geom.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

int geom_vertical_axis_reflect_in_place(matrix *mat){
    if(matrix_verrif(*mat) == 0)
        return 0;
    *mat = geom_vertical_axis_reflect(*mat);
    return 1;
}

int geom_horizontal_axis_reflect_in_place(matrix *mat){
    if(matrix_verrif(*mat) == 0)
        return 0;
    *mat = geom_horizontal_axis_reflect(*mat);
    return 1;
}

int geom_central_reflect_in_place(matrix *mat){
    if(matrix_verrif(*mat) == 0)
        return 0;
    *mat = geom_central_reflect(*mat);
    return 1;
}

int geom_rotate_in_place(matrix *mat, double angle, matrix center){
    //a faire
    return 0;
}

int geom_photomaton_in_place(matrix *mat){
    if(mat->m % 2 != 0 || mat->n % 2 != 0 || matrix_verrif(*mat) == 0)
        return 0;
    *mat = geom_photomaton(*mat);
    return 1;
}

int geom_translate_in_place(matrix *mat, matrix translation){
    if(matrix_verrif(*mat) == 0)
        return 0;
    *mat = geom_translate(*mat , translation);
    return 1;
}

int geom_zoom_in_place(matrix *mat, matrix factors){
    if(matrix_verrif(*mat) == 0)
        return 0;
    *mat = geom_zoom(*mat, factors);
    return 1;
}

matrix geom_vertical_axis_reflect(matrix mat){
    matrix res;
    if(matrix_verrif(mat) == 0){
        matrix_nulify(&res);
        return res;
    }
    int milieu = 0;
    int k = 0;
    res = matrix_create(mat.m, mat.n);
    if(mat.n % 2 == 0){
        milieu = mat.n/2;
        for (int i = 0; i < mat.m; i++)
        {
            for (int j = 0; j < milieu; j++)
            {
                printf("%d %d\n", mat.n - j - 1, j);
                res.data[i][mat.n - j - 1] = mat.data[i][j];   
            }
        }
        for (int i = 0; i < mat.m; i++)
        {
            for (int j = milieu; j < mat.n; j++)
            {
                printf("%d %d\n", milieu - k -1, j);
                res.data[i][milieu - k - 1] = mat.data[i][j];
                k++;
            }
            k=0;
        }
    }
    else{
        milieu = mat.n/2;
        for (int i = 0; i < mat.m; i++)
        {
            for (int j = 0; j < milieu; j++)
            {
                
                res.data[i][mat.n - j - 1] = mat.data[i][j];
            }
        }
        for (int i = 0; i < mat.m; i++)
        {
            for (int j = milieu; j < mat.n; j++)
            {
                res.data[i][milieu - k] = mat.data[i][j];
                k++;
            }
            k = 0;
        }
    
    }
    return res;
}

matrix geom_horizontal_axis_reflect(matrix mat){
    matrix res;
    if(matrix_verrif(mat) == 0){
        matrix_nulify(&res);
        return res;
    }
    int milieu = 0;
    int k = 0;
    res = matrix_create(mat.m, mat.n);
    if(mat.m % 2 == 0){
        milieu = mat.m/2;
        for (int i = 0; i < milieu; i++)
        {
            for (int j = 0; j < mat.n; j++)
            {
                res.data[mat.m - i - 1][j] = mat.data[i][j];   
            }
        }
        for (int i = milieu; i < mat.m; i++)
        {
            for (int j = 0; j < mat.n; j++)
            {
                res.data[milieu - k - 1][milieu - k - 1] = mat.data[i][j];
            }
            k++;
        }
    }
    else{
        milieu = mat.m/2;
        for (int i = 0; i < milieu; i++)
        {
            for (int j = 0; j < mat.n; j++)
            {              
                res.data[mat.m - i - 1][j] = mat.data[i][j];
            }
        }
        for (int i = milieu; i < mat.m; i++)
        {
            for (int j = 0; j < mat.n; j++)
            {
                res.data[milieu - k][j] = mat.data[i][j];
            }
            k++;
        }
    }
    return res;
}

matrix geom_central_reflect(matrix mat){
    matrix res;
    if(matrix_verrif(mat) == 0){
        matrix_nulify(&res);
        return res;
    }
    res = matrix_clone(mat);
    geom_vertical_axis_reflect_in_place(&res);
    geom_horizontal_axis_reflect_in_place(&res);
    return res;
}

matrix geom_rotate(matrix mat, double angle, matrix center){
    matrix res;
    if(matrix_verrif(mat) == 0){
        matrix_nulify(&res);
        return res;
    }
    return res;
}

matrix geom_photomaton(matrix mat){
    matrix res;
    if(mat.m % 2 != 0 || mat.n % 2 != 0 || matrix_verrif(mat) == 0){
        matrix_nulify(&res);
        return res;
    }
    matrix smallSquare = matrix_create(2,2);
    res = matrix_create(mat.m, mat.n);
    for (int i = 0; i < mat.m; i += 2)
    {
        for (int j = 0; j < mat.n; j += 2)
        {
            for (int ii = 0; ii < 2; ii++)
            {
                for (int jj = 0; jj < 2; jj++)
                {
                    smallSquare.data[ii][jj] = mat.data[i + ii][j + jj];
                }
            }
            res.data[0 + i / 2][0 + j / 2] = smallSquare.data[0][0];
            res.data[0 + i / 2][mat.n / 2 + j / 2] = smallSquare.data[0][1];
            res.data[mat.m / 2 + i / 2][0 + j / 2] = smallSquare.data[1][0];
            res.data[mat.m / 2 + i / 2][mat.n / 2 + j / 2] = smallSquare.data[1][1];
        }
    }
    matrix_destroy(&smallSquare);
    return res;
}

matrix geom_translate(matrix mat, matrix translation){
    matrix res;
    if(matrix_verrif(mat) == 0){
        matrix_nulify(&res);
        return res;
    }
    res = matrix_create(mat.m, mat.n);
    int translationN = translation.data[0][0];
    int translationM = translation.data[0][1];
    for (int i = 0; i < mat.m; i++)
    {
        for (int j = 0; j < mat.n; j++)
        {
            if(i +  translationM < mat.m && j + translationN < mat.n 
                && i +  translationM >= 0 && j + translationN >= 0){
                res.data[i + translationM][j + translationN] = mat.data[i][j];
            }
        }
    }
    return res;
}

matrix geom_zoom(matrix mat, matrix factors){   
    matrix res;
    if(matrix_verrif(mat) == 0){
        matrix_nulify(&res);
        return res;
    }
    res = matrix_clone(mat);
    matrix matZoom = matrix_create(mat.m * factors.data[0][0],mat.n * factors.data[0][1]);
    int roundi;
    int roundj;
    for (int i = 0; i < matZoom.m; i++)
    {
        for (int j = 0; j < matZoom.n; j++)
        {
            roundi = i/factors.data[0][0];
            roundj = j/factors.data[0][1];
            matZoom.data[i][j] = mat.data[roundi][roundj];
        }
    }
    for (int i = 0; i < mat.m; i++)
    {
        for (int j = 0; j < mat.n; j++)
        {
            if (i >= matZoom.m || j >= matZoom.n)
                res.data[i][j] = 0;
            else
                res.data[i][j] = matZoom.data[i][j];
        }
    }
    matrix_destroy(&matZoom);
    return res;
}