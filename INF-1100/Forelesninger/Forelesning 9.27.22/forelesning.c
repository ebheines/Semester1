#include <stdio.h>

int endre_tall (int *tall){
    tall += 2;
    return tall;
}


int main() {
    int mitt_tall = 2;

    printf("Mitt tall er %d\n", mitt_tall);
    //printf("Mitt tall ligger på plass 0x%x\n", &mitt_tall);
    endre_tall(&mitt_tall);
    printf("Mitt tall er nå %d\n", mitt_tall);

    return 0;
}