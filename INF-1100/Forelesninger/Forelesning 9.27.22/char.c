#include <stdio.h>

int main (){
    char tekst[] = "Hallo";
    for (int i = 0; i < 5; i++)
    {
    printf ("%c", *(tekst + i));
    printf ("%c", tekst[i]);
    }

    printf ("\n");    

    printf ("---------\n");

    int tall[] = {1, 5, 7, 2};
    for (int i = 0; i < 5; i++){
        printf ("%d\n", tall[i]);
    }
    
    char *streng;
    char **strings;
    //En peker til pekere av strenger

    printf("\n");
}