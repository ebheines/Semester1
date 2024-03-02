#include <stdio.h>

void sorter(char *A, int n){
    char tmp;
    int i = n-1;
    int j = 0;

    while(j < i){
    tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
    i--;
    j++;
    }
}

int main(){
    char A[] = "Hello world, im Eskil";
    printf("Char A: ");
    printf("%s", A);
    printf("\n");

    sorter(A, 21);
    printf("%s", A);
    printf("\n");

}