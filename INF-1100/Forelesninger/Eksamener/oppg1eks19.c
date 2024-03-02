#include <stdio.h>

int main(){
    int x = 128;
    char *y = "128";
    int z[] = {1, 2, 8};

    if(y[0] == z[0]){
        printf("%d\n", x + z[1]);
    } 
    else{
        printf("%d\n", x / z[1]);
    }

    printf("%d\n", *y);
    return 0;
}
