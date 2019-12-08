#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

int matrix_verrif(matrix mat)
{
    if(mat.data == NULL || mat.m < 1 || mat.n < 1)
        return 0;
    return 1;
}

void matrix_nulify(matrix *mat)
{
    mat->data = NULL;
    mat->m = -1;
    mat->n = -1;
}

matrix matrix_create(int m, int n){
    matrix mat;
    mat.m = m;
    mat.n = n;
    mat.data = malloc(mat.m * sizeof(double*));
    for (int i = 0; i < mat.m; i++)
    {
        mat.data[i] = malloc(mat.n * sizeof(double));
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat.data[i][j] = 0;
        }
    }
    return mat; 
}

void matrix_destroy(matrix *mat){
    for (int i = 0; i < mat->m; i++)
    {
        free(mat->data[i]);
    }
    mat->data = NULL;
    mat->m = -1;
    mat->n = -1;
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
    if (m > 0 && n > 0){
        matrix matemp = matrix_clone(*mat);
        matrix_destroy(mat);
        *mat = matrix_create(m, n);
        mat->m = m;
        mat->n = n;

        for(int i = 0; i <m; i++){
            for(int j = 0; j<n; j++){
                if (i<matemp.m && j<matemp.n)
                    mat->data[i][j] = matemp.data[i][j];
                else
                    mat->data[i][j] = 0;

            }
        }
        matrix_destroy(&matemp);
        return 1;
    }
    else
        return 0;
}

bool matrix_is_approx_equal(matrix mat1, matrix mat2, double epsilon){
    double ep_max = 0.0;
    double ep_min = 0.0;
    if(mat1.m == mat2.m && mat1.n == mat2.n && epsilon > 0)
    {
        for (int i = 0; i < mat1.m; i++)
        {
            for (int j = 0; j < mat1.n; j++)
            {
                ep_max = mat2.data[i][j]+epsilon;
                ep_min = mat2.data[i][j]-epsilon;
            if (mat1.data[i][j] > ep_max || mat1.data[i][j] < ep_min)
                return false;
            }
        }
    return true;
  }
  else
    return false;
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
    return true;
}

int matrix_add_in_place(matrix mat1, matrix mat2){
    if(mat1.m != mat2.m || mat1.n != mat2.n)
    {
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
        return 0;
    }
    matrix matClone = matrix_clone(*mat1);
    matrix_resize(mat1,mat1->m, mat2.n);
    for (int i = 0; i < mat1->m; i++)
    {
        for (int j = 0; j < mat1->n; j++)
        {
            mat1->data[i][j] = 0;
            for (int k = 0; k < matClone.n; k++)
            {
                mat1->data[i][j] += matClone.data[i][k] * mat2.data[k][j];
            }           
        }
    }
    matrix_destroy(&matClone);
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
        
            mat1.data[i][j] *= n;   
        }
    return 1;
}

int matrix_transpose_in_place(matrix *mat){
    matrix matClone = matrix_clone(*mat);
    matrix_resize(mat, mat->n, mat->m);
    for (int i = 0; i < matClone.n; i++)
    {
        for (int j = 0; j < matClone.m; j++)
        {
            mat->data[i][j] = matClone.data[j][i];
        }
    }
    matrix_destroy(&matClone);
    return 1;
}

int matrix_normalize_in_place(matrix mat){
    double maxM = 0;
    if(mat.data == NULL)
    	return 0;
    for (int i = 0; i < mat.m; i++)
    {
        for (int j = 0; j < mat.n; j++)
           {
               if (maxM < mat.data[i][j])
                   maxM = mat.data[i][j];
           }   
    }
    for (int i = 0; i < mat.m; ++i)
    {
        for (int j = 0; j < mat.n; j++)
           {
               mat.data[i][j] /= maxM; 
           }   
    }
    return 1;
}

int matrix_clipper_in_place(matrix mat){
    if(mat.data == NULL)
        return 0;
    for (int i = 0; i < mat.m; i++)
    {
        for (int j = 0; j < mat.n; j++)
        {
            if (mat.data[i][j] > 1)
                mat.data[i][j] = 1;
            else if (mat.data[i][j] < 0)
                mat.data[i][j] = 0;
        }
    }
    return 1;
}

int matrix_convolve_in_place(matrix *mat, matrix kernel){
    if(mat->data == NULL || kernel.data == NULL)
        return 0;
    matrix matClone = matrix_create(mat->m, mat->n);
    for (int i = 0; i < mat->m; i++)
    {
        for (int j = 0; j < mat->n; j++)
        {
            for (int keri = 0; keri < kernel.m; keri++)
            {
                for (int kerj= 0; kerj < kernel.n; kerj++)
                {
                    if(i + keri - 1 >= 0 && i + keri - 1 < mat->m &&
                        j + kerj - 1 >= 0 && j + kerj - 1 < mat->n){
                        matClone.data[i][j] += kernel.data[keri][kerj] * mat->data[i + keri - 1][j + kerj - 1];
                    }
                }
            } 
        }
    }
    *mat = matrix_clone(matClone);
    return 1;
}

matrix matrix_add(matrix mat1, matrix mat2){
    matrix mat;
    if(mat1.m != mat2.m || mat1.n != mat2.n)
    {
        return mat;
    }
    mat = matrix_create(mat1.m , mat1.n);
    for (int i = 0; i < mat2.m; i++)
    {
        for (int j = 0; j < mat2.n; j++)
        {
             mat.data[i][j]= mat1.data[i][j] + mat2.data[i][j];
        }
    }
    return mat;
}

matrix matrix_sub(matrix mat1, matrix mat2){
    matrix mat;
    if(mat1.m != mat2.m || mat1.n != mat2.n)
    {
        return mat;
    }
    mat = matrix_create(mat1.m , mat1.n);
    for (int i = 0; i < mat2.m; i++)
    {
        for (int j = 0; j < mat2.n; j++)
        {
             mat.data[i][j]= mat1.data[i][j] - mat2.data[i][j];
        }
    }
    return mat;
}

matrix matrix_mult(matrix mat1, matrix mat2){
    matrix mat;
    if(mat1.m != mat2.n)
    {
        return mat;
    }
    mat = matrix_create(mat1.m , mat2.n);
    for (int i = 0; i < mat.m; i++)
    {
        for (int j = 0; j < mat.n; j++)
        {
            for (int k = 0; k < mat1.n; k++)
            {
                mat.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
            }
            mat.data[i][j] = round(mat.data[i][j]);
        }
    }
    return mat;
}

matrix matrix_add_scalar(matrix mat, double n){
    matrix newmat = matrix_clone(mat);
    for (int i = 0; i < newmat.m; i++)
    {
        for (int j = 0; j < newmat.n; j++)
        {
            newmat.data[i][j] += n;   
        }
    }
    return newmat;
}

matrix matrix_mult_scalar(matrix mat, double n){
    matrix newmat = matrix_clone(mat);
    for (int i = 0; i < newmat.m; i++)
    {
        for (int j = 0; j < newmat.n; j++)
        {
            newmat.data[i][j] *= n;   
        }
    }
    return newmat;
}

matrix matrix_transpose(matrix mat){
    matrix newmat = matrix_create(mat.n, mat.m);
    for (int i = 0; i < mat.n; i++)
    {
        for (int j = 0; j < mat.m; j++)
        {
            newmat.data[i][j] = mat.data[j][i];
        }
    }
    return newmat;
}

matrix matrix_normalize(matrix mat){
    matrix newmat;
    if(mat.data == NULL)
    	return newmat;
    double maxM = 0;
    newmat = matrix_create(mat.m, mat.n);
    for (int i = 0; i < mat.m; i++)
    {
        for (int j = 0; j < mat.n; j++)
           {
               if (maxM < mat.data[i][j])
                   maxM = mat.data[i][j];
           }   
    }
    for (int i = 0; i < mat.m; ++i)
    {
        for (int j = 0; j < mat.n; j++)
           {
               newmat.data[i][j] = mat.data[i][j] / maxM; 
           }   
    }
    return newmat;
}

matrix matrix_clipper(matrix mat){
    matrix newmat;
    if(mat.data == NULL)
        return newmat;
    newmat = matrix_clone(mat);
    for (int i = 0; i < mat.m; i++)
    {
        for (int j = 0; j < mat.n; j++)
        {
            if (newmat.data[i][j] > 1)
                newmat.data[i][j] = 1;
            else if (newmat.data[i][j] < 0)
                newmat.data[i][j] = 0;
        }
    }
    return newmat;
}

matrix matrix_convolve(matrix mat, matrix kernel){
    matrix newmat;
    if(mat.data == NULL || kernel.data == NULL)
        return newmat;
    newmat = matrix_create(mat.m, mat.n);
    for (int i = 0; i < mat.m; i++)
    {
        for (int j = 0; j < mat.n; j++)
        {
            for (int keri = 0; keri < kernel.m; keri++)
            {
                for (int kerj= 0; kerj < kernel.n; kerj++)
                {
                    if(i + keri - 1 >= 0 && i + keri - 1 < mat.m &&
                        j + kerj - 1 >= 0 && j + kerj - 1 < mat.n){
                        newmat.data[i][j] += kernel.data[keri][kerj] * mat.data[i + keri - 1][j + kerj - 1];
                    }
                }
            } 
        }
    }
    return newmat;
}