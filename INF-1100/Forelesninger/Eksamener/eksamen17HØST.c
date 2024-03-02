#include <stdio.h>
// Eksamen 2017 HØST

// Oppgave 3b)

int forekommer(int *A, int lengdeA, int k){
    int antall = 0;
    for(int i = 0; i < lengdeA; i++){
        if(k == A[i]){
            antall++;
        }
    }
    return antall;
}

void frekvens(int *A, int lengdeA, int *B){
    for(int i = 0; i < lengdeA; i++){
        B[i] = forekommer(A, lengdeA, i);
    }
}

void printArray(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d - ", A[i]);
    }
    printf("\n");
}

int main(){
    int A[100];
    int B[100];
    for(int i = 0; i < 100; i++){
        A[i] = i;
    }
    printArray(A, 100);
    frekvens(A, 100, B);
    printArray(B, 100);

}