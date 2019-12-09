#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include "matrix.h"
#include "pgm.h"
#include "geom.h"
#include "filter.h"
#include <ctype.h>

int check_if_number(char *token)
{
	for (unsigned int i = 0; i < strlen(token); i++)
	{
		if (!isdigit(token[i]) && token[i] != '.')
			return 0;
	}
	return 1;
}

int getcommand(char *line, pgm *image){
	char *token = strtok(line," \n\t\f");
	if (strcmp(token, "write") == 0) 
	{
		token = strtok(NULL, " \n\t\f");
		pgm_write(token, *image);
	}
	else if (strcmp(token, "rotate") == 0)
	{
		token = strtok(NULL, " \n\t\f");
		if (token == NULL || !check_if_number(token))
			return 0;
		double m = atoi(token);
		token = strtok(NULL, " \n\t\f");
		if (token == NULL || !check_if_number(token))
			return 0;
		double n = atoi(token);
		double array[] = {m, n};
		matrix mat = matrix_create_from_array(1,2, array);
		token = strtok(NULL, " \n\t\f");
		if (token == NULL || !check_if_number(token))
			return 0;
		int angle = atoi(token);
		geom_rotate_in_place(&image->mat, angle, mat);
		matrix_destroy(&mat);
	}
	else if (strcmp(token, "translate") == 0)
	{
		token = strtok(NULL, " \n\t\f");
		if (token == NULL || !check_if_number(token))
			return 0;
		double m = atoi(token);
		token = strtok(NULL, " \n\t\f");
		if (token == NULL || !check_if_number(token))
			return 0;
		double n = atoi(token);
		double array[] = {m, n};
		matrix mat = matrix_create_from_array(1,2, array);
		geom_translate_in_place(&image->mat, mat);
		matrix_destroy(&mat);
	}
	else if (strcmp(token, "zoom") == 0)
	{
		token = strtok(NULL, " \n\t\f");
		if (token == NULL || !check_if_number(token))
			return 0;
		double m = atoi(token);
		token = strtok(NULL, " \n\t\f");
		if (token == NULL || !check_if_number(token))
			return 0;
		double n = atoi(token);
		double array[] = {m, n};
		matrix mat = matrix_create_from_array(1,2, array);
		geom_zoom_in_place(&image->mat, mat);
		matrix_destroy(&mat);
	}
	else if (strcmp(token, "resize") == 0)
	{
		token = strtok(NULL, " \n\t\f");
		if (token == NULL || !check_if_number(token))
			return 0;
		int m = atoi(token);
		token = strtok(NULL, " \n\t\f");
		if (token == NULL || !check_if_number(token))
			return 0;
		int n = atoi(token);
		matrix_resize(&image->mat, m, n);
	}
	else if (strcmp(token, "photomaton") == 0)
		geom_photomaton_in_place(&image->mat);
	else if (strcmp(token, "sharpen") == 0)
	  	filter_sharpen_in_place(&image->mat);
	else if (strcmp(token, "blur") == 0)
	 	filter_blur_in_place(&image->mat);
	else if (strcmp(token, "edge_enhance") == 0)
	 	filter_edge_enhance_in_place(&image->mat);
	else if (strcmp(token, "edge_detect") == 0)
	 	filter_edge_detect_in_place(&image->mat);
	else if (strcmp(token, "emboss") == 0)
	 	filter_emboss_in_place(&image->mat);
	else 
	{
		return 0;
	}
	return 1;
}

int main(int argc, char *argv[]) {
	argc++;
	FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;
    int erreur = 0;
    pgm image;
    fp = fopen(argv[1], "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, fp)) >= 0) {
    	if (i == 0)
    	{
    		char *token = strtok(line," \n\t\f");
    		if (strcmp(token, "read") != 0)
    		{
    			printf("La premiere commande doit etre un read\n");
    			return 0;
    		}
    		token = strtok(NULL, " \n\t\f");
    		image = pgm_read(token);
    		if(image.max == -1)
    		{
    			printf("Fichier non trouve\n");
    			exit(EXIT_FAILURE);
    		}
    	}
    	else
    	{	
    		erreur = getcommand(line, &image);
    		if (erreur == 0)
    			printf("Erreur de commande ligne %d.\n", i + 1);
    	}
		i++;
    }
    pgm_destroy(&image);
    fclose(fp);
    if (line)
        free(line);
    return 1;
}