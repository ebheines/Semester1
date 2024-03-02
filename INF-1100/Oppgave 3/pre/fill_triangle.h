#ifndef FILL_TRIANGLE_H_
#define FILL_TRIANGLE_H_

void print_triangle(triangle_t *triangle, char *msg);
int sanity_check_triangle(SDL_Surface *surface, triangle_t *triangle);
void translate_triangle(triangle_t *triangle);
void calculate_triangle_bounding_box(triangle_t *triangle);
void RotateTriangle(triangle_t *triangle);

#endif
