#include <stdio.h>
#include <stdlib.h>

/*
1. Forstå problemet
2. Lag en plan for å løse problemet
3. Utfør planen
4. Er du overbevist over problemløsningen?
*/

    

int main(){
    int A[] = {2,4,3,1,8,6};
    int i;
    int sum = 0;
    int temp = 0;

    // printf("%d %d\n", A[0], *A);
    // printf("%d %d\n", A[1], *(A+1));

    int *B = malloc(sizeof(int)*4);
    B[0] = 0;
    B[1] = 1;
    B[2] = 2;
    B[3] = 3;

    // printf("%d %d\n", B[0], *B);
    // printf("%d %d\n", B[1], *(B+1));

    float size = sizeof(A)/sizeof(A[0]);

    printf("Antall elementer i listen: %f\n", size);

    for(i = 0; i < size; i++){
        sum += A[i];
    }

    printf("Summen av elementene i array er: %d\n", sum);
    
    float gjennomsnitt = sum / size;

    printf("Gjennomsnittet av elementene er: %f\n", gjennomsnitt);

    printf("------------------------\n");

    printf("Unsorted order of array: ");
    for(i = 0; i < size; i++){
        printf("%d, ", A[i]);
    }

    printf("\n");

    for(int y = 0; y < size; y++){
        for(int x = 0; x < size; x++){
            if(A[x] < A[y]){
                temp = A[x];
                A[x] = A[y];
                A[y] = temp;
            }
        }
    }

    printf("Sorted order of array: ");
    for(i = 0; i < size; i++){
        printf("%d, ", A[i]);
    }

    printf("\n");

    return 0;
}