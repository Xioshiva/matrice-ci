#include "gfx.h"
#include <stdio.h>
#include <stdlib.h>    
#include <time.h>  

int global_m = 0;
int global_n = 0;

void render_image(int m, int n, struct gfx_context_t** context){
    if(*context==NULL) {
        *context = gfx_create("Image", n, m);
        global_m = m;
        global_n = n;
    }
    if(global_m!=m || global_n!=n){
        global_m = m;
        global_n = n;
        *context = gfx_update(*context, m, n);
    }
    
    if (!*context) {
        fprintf(stderr, "Graphic mode initialization failed!\n");
        return;
    }
    SDL_ShowCursor(SDL_ENABLE);
    gfx_clear(*context, COLOR_BLACK);
    for(int y = 0; y < m; y++) {
		for(int x = 0; x < n; x++){
            uint32_t px = (uint32_t)((double)rand()/(double)RAND_MAX * 255.0);
            uint32_t color = MAKE_COLOR(px, px, px);
            gfx_putpixel(*context, x, y, color);
        }
    }
} 

int main() {

    srand(time(NULL));
    struct gfx_context_t* context = NULL;
    printf("press ENTER to continue\n");
    while(gfx_keypressed() != SDLK_RETURN){
        render_image(600, 600, &context);
        gfx_present(context);
    }
    gfx_destroy(context);
}