#include <stdio.h>
#include <stdlib.h>

// Dynamisk minne
// Hvor mye minne vi trenger til koden vår
// malloc, calloc er i "stblib.h"

// memory leak; når minne ikke blir "freed" 


int main() {
    char *random_string;

    // malloc 
    random_string = malloc(sizeof(char));
    //*random_string = '2';
    random_string = malloc(100*sizeof(char));

    // calloc kaller 100 elemnter, alle satt til 0
    random_string = calloc(100, sizeof(char));

    // forteller OS at vi er ferdig å bruke pekeren
    free(random_string);

    printf("%d\n", &random_string);
}