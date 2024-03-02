#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "triangle.h"
#include "drawline.h"
#include "fill_triangle.h"

#define TRIANGLE_PENCOLOR   0xBBBB0000

/*
 * Fill the triangle on the surface with the triangle's color
 */
void b_fill_triangle(SDL_Surface *surface, triangle_t *triangle)
{
    // TODO: Insert code that fills the triangle with the color specified in triangle->fillcolor.
    // Hint: Draw the triangle with color TRIANGLE_PENCOLOR (this color can not
    // occur in e.g. the teapot or the example triangles).  Thus, if your 
    // approach to filling the triangle relies on looking for the edges of
    // the triangle on the surface (via the GetPixel function), you will find those
    // edges even if the triangle overlaps with a triangle that has already
    // been drawn on the surface.

        int y;
        int x;
        int xmax;
        int ymax;

     for(y = triangle->rect.y; y <= triangle->rect.h; y++){
        for(x = triangle->rect.x;x <= triangle->rect.w; x++)
        if(get_pixel(surface, x, y) == TRIANGLE_PENCOLOR){
            break;
        }
        for(xmax = triangle->rect.w;xmax > triangle->rect.x; xmax--)
        if(get_pixel(surface, xmax, y) == TRIANGLE_PENCOLOR){
            break;
        }
        draw_line(surface, x, y, xmax, y, triangle->fillcolor);
     }
}


/*
 * Draw a filled triangle on the given surface
 */
void b_draw_triangle(SDL_Surface *surface, triangle_t *triangle)
{
    RotateTriangle(triangle);

    int isOK;
    
    /* Translate. */
    translate_triangle(triangle);
    
    /* Determine bounding box */
    calculate_triangle_bounding_box(triangle);

    /* Sanity check that triangle is within surface boundaries. */
    isOK = sanity_check_triangle(surface, triangle);
    if (!isOK) {
        print_triangle(triangle, "Triangle outside surface boundaries");
        return;
    }

    /* 
     * TODO: Insert calls to draw_line to draw the triangle.
     * Remember to use the on-surface coordinates (triangle->sx1, etc.)
     */

    draw_line(surface, triangle->sx1, triangle->sy1, triangle->sx2, triangle->sy2, TRIANGLE_PENCOLOR);
    draw_line(surface, triangle->sx2, triangle->sy2, triangle->sx3, triangle->sy3, TRIANGLE_PENCOLOR);
    draw_line(surface, triangle->sx3, triangle->sy3, triangle->sx1, triangle->sy1, TRIANGLE_PENCOLOR);

    /* Fill triangle */
    b_fill_triangle(surface, triangle);

    // T
    draw_line(surface, 15, 10, 15, 30, TRIANGLE_PENCOLOR);
    draw_line(surface, 9, 10, 21, 10, TRIANGLE_PENCOLOR);

    // H
    draw_line(surface, 25, 10, 25, 30, TRIANGLE_PENCOLOR);
    draw_line(surface, 33, 10, 33, 30, TRIANGLE_PENCOLOR);
    draw_line(surface, 25, 20, 33, 20, TRIANGLE_PENCOLOR);

    // E
    draw_line(surface, 37, 10, 45, 10, TRIANGLE_PENCOLOR);
    draw_line(surface, 37, 20, 45, 20, TRIANGLE_PENCOLOR);
    draw_line(surface, 37, 30, 45, 30, TRIANGLE_PENCOLOR);
    draw_line(surface, 37, 10, 37, 30, TRIANGLE_PENCOLOR);



    // A
    draw_line(surface, 9, 55, 15, 35, TRIANGLE_PENCOLOR);
    draw_line(surface, 15, 35, 21, 55, TRIANGLE_PENCOLOR);
    draw_line(surface, 12, 45, 18, 45, TRIANGLE_PENCOLOR);

    // M
    draw_line(surface, 25, 35, 25, 55, TRIANGLE_PENCOLOR);
    draw_line(surface, 35, 35, 35, 55, TRIANGLE_PENCOLOR);
    draw_line(surface, 25, 35, 30, 40, TRIANGLE_PENCOLOR);
    draw_line(surface, 30, 40, 35, 35, TRIANGLE_PENCOLOR);

    // A
    draw_line(surface, 39, 55, 45, 35, TRIANGLE_PENCOLOR);
    draw_line(surface, 45, 35, 51, 55, TRIANGLE_PENCOLOR);
    draw_line(surface, 42, 45, 48, 45, TRIANGLE_PENCOLOR);

    // Z
    draw_line(surface, 55, 35, 65, 35, TRIANGLE_PENCOLOR);
    draw_line(surface, 55, 55, 65, 55, TRIANGLE_PENCOLOR);
    draw_line(surface, 65, 35, 55, 55, TRIANGLE_PENCOLOR);

    // I
    draw_line(surface, 69, 35, 73, 35, TRIANGLE_PENCOLOR);
    draw_line(surface, 69, 55, 73, 55, TRIANGLE_PENCOLOR);
    draw_line(surface, 71, 35, 71, 55, TRIANGLE_PENCOLOR);

    // N
    draw_line(surface, 77, 35, 77, 55, TRIANGLE_PENCOLOR);
    draw_line(surface, 87, 35, 87, 55, TRIANGLE_PENCOLOR);
    draw_line(surface, 77, 35, 87, 55, TRIANGLE_PENCOLOR);

    // G
    draw_line(surface, 91, 35, 101, 35, TRIANGLE_PENCOLOR);
    draw_line(surface, 91, 35, 91, 55, TRIANGLE_PENCOLOR);
    draw_line(surface, 91, 55, 101, 55, TRIANGLE_PENCOLOR);
    draw_line(surface, 101, 48, 101, 55, TRIANGLE_PENCOLOR);
    draw_line(surface, 101, 48, 97, 48, TRIANGLE_PENCOLOR);



    // T
    draw_line(surface, 15, 60, 15, 80, TRIANGLE_PENCOLOR);
    draw_line(surface, 9, 60, 21, 60, TRIANGLE_PENCOLOR);

    // E
    draw_line(surface, 25, 60, 33, 60, TRIANGLE_PENCOLOR);
    draw_line(surface, 25, 70, 33, 70, TRIANGLE_PENCOLOR);
    draw_line(surface, 25, 80, 33, 80, TRIANGLE_PENCOLOR);
    draw_line(surface, 25, 60, 25, 80, TRIANGLE_PENCOLOR);

    // A
    draw_line(surface, 37, 80, 43, 60, TRIANGLE_PENCOLOR);
    draw_line(surface, 43, 60, 49, 80, TRIANGLE_PENCOLOR);
    draw_line(surface, 40, 70, 46, 70, TRIANGLE_PENCOLOR);

    // P
    draw_line(surface, 53, 60, 61, 60, TRIANGLE_PENCOLOR);
    draw_line(surface, 53, 70, 61, 70, TRIANGLE_PENCOLOR);
    draw_line(surface, 53, 60, 53, 80, TRIANGLE_PENCOLOR);
    draw_line(surface, 61, 70, 61, 60, TRIANGLE_PENCOLOR);

    // O
    draw_line(surface, 65, 60, 73, 60, TRIANGLE_PENCOLOR);
    draw_line(surface, 65, 80, 73, 80, TRIANGLE_PENCOLOR);
    draw_line(surface, 65, 60, 65, 80, TRIANGLE_PENCOLOR);
    draw_line(surface, 73, 60, 73, 80, TRIANGLE_PENCOLOR);

    // T
    draw_line(surface, 77, 60, 87, 60, TRIANGLE_PENCOLOR);
    draw_line(surface, 82, 60, 82, 80, TRIANGLE_PENCOLOR);
}