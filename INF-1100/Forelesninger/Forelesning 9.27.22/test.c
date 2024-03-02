#include <stdio.h>

// void-funksjonen gjør at vi kan flytte stringen får et gitt 
// antall plasse, i dette tilfellet 3

void cipher (char my_string[], int key){
    for (int i = 0; i < 100 && my_string[i] != '\0'; i++){
        my_string[i] += key;
    }
    
}

int main(){
    char my_string[] = "Eskil er en dritt";
    printf ("Original string: %s\n", my_string);

    // vi krypterer my_string og flytter de 3 fram
    cipher(my_string, 2);
    printf ("Encrypted string: %s\n", my_string);
    return 0;
}