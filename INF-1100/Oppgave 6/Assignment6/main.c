#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL.h>
#include "drawline.h"
#include "triangle.h"
#include "list.h"
#include "teapot_data.h"
#include "sphere_data.h"
#include "object.h"

/* Two macro's that find the lesser or greater of two values */
#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)

/*
 * Clear the surface by filling it with 0x00000000(black).
 */
void clear_screen(SDL_Surface *surface)
{
    if(SDL_FillRect(surface, NULL, 0x00000000) < 0){
        fprintf(stderr, "Unable to clear the surface. Error returned: %s\n", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
}

/*
 * Accelerate the object; altering its speed based on the boost given.
 */
void accelerate_object(object_t *a, float boost, float maxspeed)
{
    float s;
    float news;
    
    /* Calculate lenght of speed vector */
    s = sqrtf(a->speedx * a->speedx + a->speedy * a->speedy);

    /* Boost speed */
    news = s * boost;
    if (news < 0.0)
        news = 0.0;
    if (news > maxspeed)
        news = maxspeed;    
    a->speedx *= news/s;
    a->speedy *= news/s;
}

/*
 * Animate bouncing balls on the screen.
 */
void bouncing_balls(SDL_Window *window)
{
    SDL_Surface *surface;

    surface = SDL_GetWindowSurface(window);
    if(!surface){
        fprintf(stderr, "Unable to create surface: %s\n", SDL_GetError());
    }

    object_t *player;

    list_iterator_t *iter;
    list_t *list = list_create();
    iter = list_createiterator(list);

    for(int i = 0; i < 3; i++){
        player = create_object(surface, sphere_model, SPHERE_NUMTRIANGLES);
        list_addfirst(list, player);
    }

    list_resetiterator(iter);

    while((player = list_next(iter))){
        player->tx = (float) 800;
        player->ty = (float) 800;
        draw_object(player);
    }

}

int main(void)
{
    const size_t bufsize = 100;
    
    /* Change the screen width and height to your own liking */
    const int screen_w = 2000;
    const int screen_h = 1100;

    char errmsg[bufsize];
    SDL_Window *window;

    /* Initialize SDL */
    if (SDL_Init(SDL_INIT_VIDEO) < -1) {
        snprintf(errmsg, bufsize, "Unable to initialize SDL.");
        goto error;
    }
    
    /* Create a 1600x900 window */
    window = SDL_CreateWindow("The Amazing Bouncing Balls",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              screen_w, screen_h,
                              0);
    if(!window) {
        snprintf(errmsg, bufsize, "Unable to get video surface.");
        goto error;
    }

    SDL_Surface *surface;
    SDL_Event event;

    surface = SDL_GetWindowSurface(window);
    if(!surface){
        fprintf(stderr, "Unable to create surface: %s\n", SDL_GetError());
    }

    int done = 0;

    while(!done){
        SDL_GetTicks();
        clear_screen(surface);

        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    done = 1;
                    break;
                case SDL_WINDOWEVENT:
                    if(event.window.event == SDL_WINDOW_SHOWN){
                        SDL_SetWindowPosition(window, 50, 50);
                        break;
                    }
            }
        }
        SDL_UpdateWindowSurface(window);
        SDL_Delay(10);
    }

    /* Start bouncing some balls */
    bouncing_balls(window);

    /* Shut down SDL */
    SDL_Quit();

    /* Wait a little bit jic something went wrong (so that printfs can be read) */
    SDL_Delay(5000);
    
    return 0;

    /* Upon an error, print message and quit properly */
error:
    fprintf(stderr, "%s Error returned: %s\n", errmsg, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}
