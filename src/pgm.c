#include "pgm.h"

pgm pgm_read(char *filename){
    pgm res;
    return res;
}

void pgm_destroy(pgm *image){}

int pgm_write(char *filename, pgm image){
    return 0;
}

bool pgm_is_equal(pgm i1, pgm i2){
    return false;
}

bool pgm_is_approx_equal(pgm i1, pgm i2, double epsilon){
    return false;
}