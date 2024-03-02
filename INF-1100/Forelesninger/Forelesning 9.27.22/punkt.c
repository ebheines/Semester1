#include <stdio.h>

//Typedef, vet ikke
typedef struct punkt punkt_t;

//struct vet ikke
struct punkt
{
    int x;
    int y;
    char *navn;
};

void print_punkt(punkt_t *punkt){

//Printer punkt x og y, peker til minnpunkt.x og mittpunkt.y
    printf("(%d, %d)\n", punkt->x, punkt->y);
}

// -> betyr peker

int main (){
    punkt_t mitt_punkt;
    mitt_punkt.x = 10;
    mitt_punkt.y = 20;
    mitt_punkt.navn = "Hallo verden";

//Print_punkt printer punktet som er definert etter mitt_punkt.x/y
    print_punkt(&mitt_punkt);

}
