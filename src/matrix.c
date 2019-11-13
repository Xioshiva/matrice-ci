#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

matrix matrix_create(int m, int n){
    matrix mat;
    mat.m = m;
    mat.n = n;
    mat.data = malloc(mat.m * sizeof(double*));
    for (int i = 0; i < mat.m; i++)
    {
        mat.data[i] = malloc(mat.n * sizeof(double));
    }
    return mat; 
}

void matrix_destroy(matrix *mat){
    for (int i = 0; i < mat->m; i++)
    {
        free(mat->data[i]);
    }
    free(mat->data);
}

matrix matrix_create_from_array(int m, int n, double data[]){
    matrix mat = matrix_create(m,n);
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat.data[i][j] = data[k];
            k++;
        }
    }
    return mat; 
}

matrix matrix_clone(matrix mat){
    matrix matClone = matrix_create(mat.m, mat.n);
    for (int i = 0; i < mat.m; i++)
    {
        for (int j = 0; j < mat.n; j++)
        {
            matClone.data[i][j] = mat.data[i][j];
        }
    }
    return matClone;
}

void matrix_print(matrix mat){
    for (int i = 0; i < mat.m; i++)
    {
        for (int j = 0; j < mat.n; j++)
        {
            printf("%f ", mat.data[i][j]);
        }
        printf("\n");
    }
}

int matrix_resize(matrix *mat, int m, int n){
    if(mat->m > m)
    {
        for (int i = m; i < mat->m; i++)
        {
            free(mat->data[i]);
        }
        mat->m = m;
    }
    if(mat->n > n)
    {
        mat->n = n;
    }
    if(mat->m < m || mat->n < n)
    {
        matrix Clone = matrix_clone(*mat);
        matrix_destroy(mat);
        *mat = matrix_create(m,n);
        for (int i = 0; i < Clone.m; i++)
        {
            for (int j = 0; j < Clone.n; j++)
            {
                mat->data[i][j] = Clone.data[i][j];
            }
        }
    }
    return 0;
}

bool matrix_is_approx_equal(matrix mat1, matrix mat2, double epsilon){
    epsilon = epsilon + 1;
    if(mat1.m != mat2.m || mat1.n != mat2.n)
    {
        return false;
    }
    for (int i = 0; i < mat2.m; i++)
    {
        for (int j = 0; j < mat2.n; j++)
        {
            if(mat1.data[i][j] != mat2.data[i][j])
                return false;
        }
    }
    return true;
}

bool matrix_is_equal(matrix mat1, matrix mat2){
    if(mat1.m != mat2.m || mat1.n != mat2.n)
    {
        return false;
    }
    for (int i = 0; i < mat2.m; i++)
    {
        for (int j = 0; j < mat2.n; j++)
        {
            if(mat1.data[i][j] != mat2.data[i][j])
                return false;
        }
    }
    printf("true");
    return true;
}

int matrix_add_in_place(matrix mat1, matrix mat2){
    if(mat1.m != mat2.m || mat1.n != mat2.n)
    {
        printf("Doivent etre de la meme taille");
        return 0;
    }
    for (int i = 0; i < mat2.m; i++)
    {
        for (int j = 0; j < mat2.n; j++)
        {
            mat1.data[i][j] += mat2.data[i][j];
        }
    }
    return 1;
}

int matrix_sub_in_place(matrix mat1, matrix mat2){    
    if(mat1.m != mat2.m || mat1.n != mat2.n)
    {
        printf("Doivent etre de la meme taille");
        return 0;
    }
    for (int i = 0; i < mat2.m; i++)
    {
        for (int j = 0; j < mat2.n; j++)
        {
            mat1.data[i][j] -= mat2.data[i][j];
        }
    }
    return 1;
}

int find_bigger(int nbr1, int nbr2)
{
    if(nbr1 > nbr2)
        return nbr1;
    else
        return nbr2;
}

int matrix_mult_in_place(matrix *mat1, matrix mat2){
    if(mat1->m != mat2.n)
    {
        printf("Doivent etre de la meme taille");
        return 0;
    }
    matrix_resize(mat1,find_bigger(mat1->m,mat2.m), find_bigger(mat1->n,mat2.n));
    matrix matClone = matrix_clone(*mat1);
    for (int i = 0; i < mat1->m; i++)
    {
        for (int j = 0; j < mat1->n; j++)
        {
            mat1->data[i][j] = 0;
            for (int k = 0; k < mat2.n; k++)
            {
                mat1->data[i][j] += matClone.data[i][k] * mat2.data[k][j];
            }           
        }
    }
    return 1;
}

int matrix_add_scalar_in_place(matrix mat1, double n){
    for (int i = 0; i < mat1.m; i++)
    {
        for (int j = 0; j < mat1.n; j++)
        {
            mat1.data[i][j] += n;   
        }
    }
    return 1;
}

int matrix_mult_scalar_in_place(matrix mat1, double n){
    for (int i = 0; i < mat1.m; i++)
    {
        for (int j = 0; j < mat1.n; j++)
        {
            mat1.data[i][j] *= n;   
        }
    }
    return 1;
}

int matrix_transpose_in_place(matrix *mat){
    matrix matClone = matrix_clone(*mat);
    matrix_resize(mat, mat->n, mat->m);
    for (int i = 0; i < mat->m; i++)
    {
        for (int j = 0; j < mat->n; j++)
        {
            printf("%f\n", matClone.data[i][j]);
            mat->data[mat->m - i - 1][mat->n - j - 1] = matClone.data[j][i];
        }
    }
    return 1;
}

int matrix_normamze_in_place(matrix mat){
    return 1;
}

int matrix_clipper_in_place(matrix mat){
    return 0;
}

int matrix_convolve_in_place(matrix *mat, matrix kernel){
    return 0;
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

matrix matrix_normamze(matrix mat){
    matrix newmat;
    int maxM = 0;
    for (int i = 0; i < newmat.m; i++)
    {
        for (int j = 0; j < newmat.n; j++)
           {
               if (maxM < newmat.data[i][j])
               {
                   maxM = newmat.data[i][j];
               }
           }   
    }
    for (int i = 0; i < newmat.m; ++i)
    {
        for (int j = 0; j < newmat.n; j++)
           {
               newmat.data[i][j] /= maxM; 
           }   
    }
    return newmat;
}

matrix matrix_clipper(matrix mat){
    matrix newmat;
    return newmat;
}

matrix matrix_convolve(matrix mat, matrix kernel){
    matrix newmat;
    return newmat;
}