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
void a_fill_triangle(SDL_Surface *surface, triangle_t *triangle)
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

    // for loop for cheching all the values from ymin to ymax in the bounding box
    for(y = triangle->rect.y; y < triangle->rect.h; y++){
    // for loop for checking all the values from xmin to xmax while also checkin ymin to ymax 
        for(x = triangle->rect.x; x < triangle->rect.w; x++)
    // if test that checks if the cross product of the vectors from corner1 to corner 2 and from corner 1 to a point < 0
    // for all the corners in the triangle
        if((triangle->sx2 - triangle->sx1) * (y - triangle->sy1) - (triangle->sy2 - triangle->sy1) * (x - triangle->sx1) < 0 &&
            (triangle->sx3 - triangle->sx2) * (y - triangle->sy2) - (triangle->sy3 - triangle->sy2) * (x - triangle->sx2) < 0 &&
            (triangle->sx1 - triangle->sx3) * (y - triangle->sy3) - (triangle->sy1 - triangle->sy3) * (x - triangle->sx3) < 0){
    // paints the pixel the given color if it is inside the triangle
            set_pixel(surface, x, y, triangle->fillcolor);
        }
    }

    int y2;
    int x2;

    // second algorithm that checks the same as the first one, but cross product of the vectors > 0
    for(y2 = triangle->rect.y; y2 < triangle->rect.h; y2++){
        for(x2 = triangle->rect.x; x2 < triangle->rect.w; x2++)
        if((triangle->sx2 - triangle->sx1) * (y2 - triangle->sy1) - (triangle->sy2 - triangle->sy1) * (x2 - triangle->sx1) > 0 &&
            (triangle->sx3 - triangle->sx2) * (y2 - triangle->sy2) - (triangle->sy3 - triangle->sy2) * (x2 - triangle->sx2) > 0 &&
            (triangle->sx1 - triangle->sx3) * (y2 - triangle->sy3) - (triangle->sy1 - triangle->sy3) * (x2 - triangle->sx3) > 0){
            set_pixel(surface, x2, y2, triangle->fillcolor);
        }
    }
}

/*
 * Draw a filled triangle on the given surface
 */
void a_draw_triangle(SDL_Surface *surface, triangle_t *triangle)
{
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

    draw_line(surface, triangle->sx1, triangle->sy1, triangle->sx2, triangle->sy2, triangle->fillcolor);
    draw_line(surface, triangle->sx2, triangle->sy2, triangle->sx3, triangle->sy3, triangle->fillcolor);
    draw_line(surface, triangle->sx3, triangle->sy3, triangle->sx1, triangle->sy1, triangle->fillcolor);


    /* 
     * TODO: Insert calls to draw_line to draw the triangle.
     * Remember to use the on-surface coordinates (triangle->sx1, etc.)
     */

    /* Fill triangle */
    a_fill_triangle(surface, triangle);
}
