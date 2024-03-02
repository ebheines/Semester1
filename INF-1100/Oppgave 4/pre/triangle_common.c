#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "triangle.h"
#include "drawline.h"

#define TRIANGLE_PENCOLOR   0xBBBB0000

/* 
 * Print triangle coordinates along with a message
 */
void print_triangle(triangle_t *triangle, char *msg)
{
    printf("%s: %d,%d - %d,%d - %d,%d\n",
        msg,
        triangle->x1, triangle->y1, 
        triangle->x2, triangle->y2, 
        triangle->x3, triangle->y3);
}

/*
 * Return 0 if triangle coordinates are outside the surface boundary. 1 otherwise.
 */
int sanity_check_triangle(SDL_Surface *surface, triangle_t *triangle)
{
    if (triangle->sx1 < 0 || triangle->sx1 >= surface->w ||
        triangle->sx2 < 0 || triangle->sx2 >= surface->w ||
        triangle->sx3 < 0 || triangle->sx3 >= surface->w ||
        triangle->sy1 < 0 || triangle->sy1 >= surface->h ||
        triangle->sy2 < 0 || triangle->sy2 >= surface->h ||
        triangle->sy3 < 0 || triangle->sy3 >= surface->h) {
        return 0;
    } else {
        return 1;
    }
}

/*
 * Move the triangle to the center of the surface,
 * altering the on-screen coordinates(e.g. triangle->sx1)
 */
void translate_triangle(triangle_t *triangle)
{
    // Finding the center of the preset screensize
    triangle->tx = 2000/2;
    triangle->ty = 1100/2;

    triangle->sx1 = (triangle->x1 - triangle->tx);
    triangle->sx2 = (triangle->x2 - triangle->tx);
    triangle->sx3 = (triangle->x3 - triangle->tx);
    triangle->sy1 = (triangle->y1 - triangle->ty);
    triangle->sy2 = (triangle->y2 - triangle->ty);
    triangle->sy3 = (triangle->y3 - triangle->ty);
    RotateTriangle(triangle);

    // float radiant;
    // int degree = 180;

    // radiant = degree * M_PI/180;

    // triangle->sx1 = cos(radiant)*triangle->x1 - sin(radiant)*triangle->y1;
    // triangle->sx2 = cos(radiant)*triangle->x2 - sin(radiant)*triangle->y2;
    // triangle->sx3 = cos(radiant)*triangle->x3 - sin(radiant)*triangle->y3;
    // triangle->sy1 = sin(radiant)*triangle->x1 + cos(radiant)*triangle->y1;
    // triangle->sy2 = sin(radiant)*triangle->x2 + cos(radiant)*triangle->y2;
    // triangle->sy3 = sin(radiant)*triangle->x3 + cos(radiant)*triangle->y3;

    // TODO: Insert code that moves the triangle on the surface.
    // The translation coordinates are specified in triangle->tx and triangle->ty.
    // Remember to use the on-surface coordinates (triangle->sx1, etc.)
}

/*
 * Calculate the triangle bounding box,
 * altering fields of the triangle's rect(e.g. triangle->rect.x)
 */
void calculate_triangle_bounding_box(triangle_t *triangle)
{
    // triangle->rect.w = triangle->sx1 > triangle->sx2 ? (triangle->sx1 > triangle->sx3 ? triangle->sx1 : triangle->sx3) : (triangle->sx2 > triangle->sx3 ? triangle->sx2 : triangle->sx3);
    // triangle->rect.h = triangle->sy1 > triangle->sy2 ? (triangle->sy1 > triangle->sy3 ? triangle->sy1 : triangle->sy3) : (triangle->sy2 > triangle->sy3 ? triangle->sy2 : triangle->sy3);
    // triangle->rect.x = triangle->sx1 < triangle->sx2 ? (triangle->sx1 < triangle->sx3 ? triangle->sx1 : triangle->sx3) : (triangle->sx2 < triangle->sx3 ? triangle->sx2 : triangle->sx3);
    // triangle->rect.y = triangle->sy1 < triangle->sy2 ? (triangle->sy1 < triangle->sy3 ? triangle->sy1 : triangle->sy3) : (triangle->sy2 < triangle->sy3 ? triangle->sy2 : triangle->sy3);
// 
        // Alternative way to find rect x/y/w/h
    triangle->rect.w = fmax((fmax(triangle->sx1, triangle->sx2)), triangle->sx3);
    triangle->rect.x = fmin((fmin(triangle->sx1, triangle->sx2)), triangle->sx3);
    
    triangle->rect.h = fmax((fmax(triangle->sy1, triangle->sy2)), triangle->sy3);
    triangle->rect.y = fmin((fmin(triangle->sy1, triangle->sy2)), triangle->sy3);



        // drawing the bounding boxes
    // draw_line(surface, triangle->rect.x, triangle->rect.y, triangle->rect.w, triangle->rect.w, triangle->fillcolor);
    // draw_line(surface, triangle->rect.x, triangle->rect.y, triangle->rect.h, triangle->rect.h, triangle->fillcolor);
    // draw_line(surface, triangle->rect.w, triangle->rect.h, triangle->rect.w, triangle->rect.h, triangle->fillcolor);
    // draw_line(surface, triangle->rect.h, triangle->rect.w, triangle->rect.h, triangle->rect.w, triangle->fillcolor);

    // TODO: Insert code that calculates the bounding box of a triangle.
    // Remember to use the on-surface coordinates (triangle->sx1, etc.)
    // The bounding box coordinates should be written to 
    // triangle->rect.x, triangle->rect.y, triangle->rect.w, triangle->rect.h

    
}

void RotateTriangle(triangle_t *triangle){
    float radiant;
    float degree = triangle->rotation;

    radiant = degree * M_PI/180;
    
    triangle->sx1 = cos(radiant)*triangle->x1 - sin(radiant)*triangle->y1 + triangle->tx;
    triangle->sx2 = cos(radiant)*triangle->x2 - sin(radiant)*triangle->y2 + triangle->tx;
    triangle->sx3 = cos(radiant)*triangle->x3 - sin(radiant)*triangle->y3 + triangle->tx;

    triangle->sy1 = sin(radiant)*triangle->x1 - cos(radiant)*triangle->y1 + triangle->ty;
    triangle->sy2 = sin(radiant)*triangle->x2 - cos(radiant)*triangle->y2 + triangle->ty;
    triangle->sy3 = sin(radiant)*triangle->x3 - cos(radiant)*triangle->y3 + triangle->ty;
}
