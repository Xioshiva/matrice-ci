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

pgm pgm_read(char *filename){
    pgm res;
    FILE *stream;
    stream = fopen(filename, "r");
    if (stream == NULL) {
    	res.max = -1;
        return res;
    }
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *token;
    int i = 0;
    int j = 0;
    int m = 0;
    int n = 0;
    while ((read = getline(&line, &len, stream)) != -1) {
    	token = strtok(line, " ");
        while(token != NULL ) {
        	if(i == 2){
    			   if(j == 0)				
      			   n = strToInt(token);
      			 if(j == 1){
      			   m = strToInt(token);
      			}
      			res.mat = matrix_create(m,n);
      		}
      		if(i == 3)
      			res.max = strToInt(token);
        	if(i > 3){
        		res.mat.data[i - 4][j] = strToInt(token);
          }
      		token = strtok(NULL, " ");
      		j++;
      	}
      	j = 0;
        i++;

    }
    matrix_normalize_in_place(res.mat);
    return res;
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
  fprintf(stream, "Test\n");
  fprintf(stream, "%d %d\n", image.mat.n, image.mat.m);  
  fprintf(stream, "%d\n", image.max);  
  for(int i = 0; i < image.mat.m; i++) { 
    for(int j = 0; j < image.mat.n; j++) { 
      temp = image.mat.data[i][j];
      if(j == 0)
        fprintf(stream, "%d", temp);
      else if(temp > 99)
        fprintf(stream, "%d", temp);
      else if(temp > 9)
        fprintf(stream, " %d", temp);
      else
        fprintf(stream, "  %d", temp);
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