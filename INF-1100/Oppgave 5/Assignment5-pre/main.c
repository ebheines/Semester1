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

#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)


void clear_screen(SDL_Surface *surface)
{
    if(SDL_FillRect(surface, NULL, 0x00000000) < 0){
        fprintf(stderr, "Unable to clear the surface. Error returned: %s\n", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
}

void accelerate_object(object_t *a, float boost, float maxspeed)
{
    float s;
    float news;
    
    s = sqrtf(a->speedx * a->speedx + a->speedy * a->speedy);

    news = s * boost;
    if (news < 0.0)
        news = 0.0;
    if (news > maxspeed)
        news = maxspeed;    
    a->speedx *= news/s;
    a->speedy *= news/s;
}
// Function for creating balls, adding them to the list, and the animation for the balls
void bouncing_balls(SDL_Window *window)
{
    object_t *ball;

    float ballscale, gravity, screenright, screenleft, screentop, screenbottom;
    int radius;
    unsigned int lasttime = 0, currenttime;

    SDL_Surface *surface;
    SDL_Event event;

    surface = SDL_GetWindowSurface(window);
    if (!surface) {
        fprintf(stderr, "Unable to create surface: %s\n", SDL_GetError());
    }

    ballscale = 0.1;
    radius = (int)(600 * ballscale);
    gravity = 0.3;
    screenright = (float)surface->w - radius;
    screenleft = radius;
    screentop = radius;
    screenbottom = (float)surface->h - radius;

    list_iterator_t *iter;
    list_t *list = list_create();
    iter = list_createiterator(list);

// Creates a given amount of balls and adds them to the list
// and also gives the speed of the balls
    for(int i = 0; i < 6; i++){
        ball = create_object(surface, sphere_model, SPHERE_NUMTRIANGLES);
        ball->tx = (float) 150;
        ball->ty = (float) 150;
        ball->speedx = (float) ((rand() % 20) - 10) * 1.5;
        ball->scale = ballscale;
        list_addfirst(list, ball);
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
                    if(event.window.event == SDL_WINDOW_SHOWN) {
                        SDL_SetWindowPosition(window, 50, 50);
                        break;
                        }
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == SDLK_SPACE){
                        ball = create_object(surface, teapot_model, TEAPOT_NUMTRIANGLES);
                        ball->tx = (float) 150;
                        ball->ty = (float) 150;
                        ball->speedx = (float) ((rand() % 8) + 4);
                        ball->scale = ballscale;
                        list_addfirst(list, ball);
                        }
            }
        }

        list_resetiterator(iter);
// Iterates through the list to draw the balls we have created and added to the list
// and if there are balls in the list, the balls will move and bounce
        while((ball = list_next(iter))){
        ball->tx += ball->speedx;
        ball->ty += ball->speedy;
        ball->speedy += gravity;
        ball->rotation += ball->speedx;
        draw_object(ball);
        
// Animation for when the ball hits the top/buttom of the screen, making it slow down
        if(ball->ty >= screenbottom || ball->ty <= screentop){
            ball->speedy *= -0.8;
            ball->speedx *= 0.8;
        }

// Animation for then the sides of the screen, making it bounce back 
        if(ball->tx >= screenright || ball->tx <= screenleft){
            ball->speedx *= -1;
        }

// Removes the balls 5 seconds after they stop at the buttom of the screen
        if((fabsf(ball->speedy) < 0.08 && fabsf(ball->speedx) < 0.08)){
            currenttime = SDL_GetTicks();
            if(currenttime > lasttime + 5000){
            list_remove(list, ball);
            destroy_object(ball);
            printf("Ball destoyed");    
            }
        }
        
// Closes the SDL-window when all the balls are removed
        if(list_size(list) < 1 && currenttime > 7000)
            SDL_Quit();
        }

        SDL_UpdateWindowSurface(window);
        SDL_Delay(10);
        
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
