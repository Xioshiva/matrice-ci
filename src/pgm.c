#define _GNU_SOURCE
#include "pgm.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>

double strToInt(char *str)
{
  double nbr = 0;
  int c = 0;
  double puissance = 1;
  while (str[c] != '\0' && str[c] != '\n')
   c++;
  for (int i = c - 1; i >= 0; i--)
  {
    nbr += (str[i] - 48) * puissance;
    puissance *= 10;
  }
  return nbr;
}

pgm pgm_read(char *filename)
{
    char *line = NULL;
    size_t len = 0;
    FILE * fp = fopen(filename, "r");
    if (!fp){
      pgm failed;
      failed.max = -1;
      return failed;
    }
    pgm matrix_read;
    int i = 0, j = 0;
    int m = -1, n = -1;
    int size_array = -1;
    int k = 1;
    double* array = NULL;
    char *token;
    while(getline(&line, &len, fp) >= 0)
    {
      token = strtok(line," \n\t\f");
      while (token != NULL)
      {
        if(token[0] == '#')
          k++;
        if(i == k && j == 0)
        {
          n = strToInt(token);
          j++;
        }
        else if (i == k && j == 1)
        {
          m = strToInt(token);
          size_array = m * n;
          array = malloc(size_array * sizeof(double));
          j = 0;
        }
        else if (i == k + 1)
          matrix_read.max = strToInt(token);
        else if (i >= k + 2)
        {
          array[j] = strToInt(token);
          j++;
        }
        token = strtok(NULL, " \n\t\f");
    }
    i++;
  }
  free(token);
  free(line);
  matrix tmp_matrix = matrix_create_from_array(m,n,array);
  matrix_normalize_in_place(tmp_matrix);
  matrix_read.mat = matrix_clone(tmp_matrix);
  free(array);
  matrix_destroy(&tmp_matrix);
  fclose(fp);
  return matrix_read;
}


void pgm_destroy(pgm *image){
  matrix_destroy(&image->mat);
  image->max = -1;
}

int pgm_write(char *filename, pgm image){
  int temp = 0;
  FILE *stream;
  matrix_mult_scalar_in_place(image.mat, image.max);
  stream = fopen(filename, "wb"); 
  fprintf(stream, "P2\n");
  fprintf(stream, "%d %d\n", image.mat.n, image.mat.m);  
  fprintf(stream, "%d\n", image.max);  
  for(int i = 0; i < image.mat.m; i++) { 
    for(int j = 0; j < image.mat.n; j++) { 
      temp = image.mat.data[i][j];
      fprintf(stream, "%d ", temp);
    }
    fprintf(stream, "\n"); 
    } 
  fclose(stream);
  matrix_normalize_in_place(image.mat);
  return 1;
}


bool pgm_is_equal(pgm i1, pgm i2){
  if(i1.max != i2.max)
    return false;
  if(matrix_is_equal(i1.mat, i2.mat) == false)
    return false;
  return true;
}

bool pgm_is_approx_equal(pgm i1, pgm i2, double epsilon){
  if(i1.max != i2.max)
    return false;
  if(matrix_is_approx_equal(i1.mat, i2.mat, epsilon) == false)
    return false;
  return true;
}