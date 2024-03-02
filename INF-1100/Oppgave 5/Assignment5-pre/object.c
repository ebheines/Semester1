#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "drawline.h"
#include "triangle.h"
#include "object.h"


object_t *create_object(SDL_Surface *surface, triangle_t *model, int numtriangles)
{
// Pointing to which struct we use. Allocate the memory of the object
    object_t *object = (object_t*) malloc(sizeof(object_t));

    object->model = model;
    object->numtriangles = numtriangles;
    object->surface = surface;

    return object;
}

void destroy_object(object_t *object)
{
// Freeing the object from the allocated memory, aka the heap
    free(object);

}

void draw_object(object_t *object)
{
// Looping through all the triangles in the sphere_data to make all the triangles in the ball/sphere
// on the surface of the SDL-screen
    for(int i = 0; i < object->numtriangles; i++){
        object->model[i].tx = object->tx;   
        object->model[i].ty = object->ty;
        object->model[i].scale = object->scale;
        object->model[i].rotation = object->rotation;
        draw_triangle(object->surface, &object->model[i]);
    }
} 
