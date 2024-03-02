#include <stdio.h>

//OPPGAVE 3a
void forekommer(int *A, int n, int k){
    printf("Velg et tall for å se hvor mange gang det forekommer i arrayet: ");
    scanf("%d", &k);

    printf("\n");

    int antall = 0;

    for(int i = 0; i < n; i++){
        if(A[i] == k)
            antall++;
        
    }

    printf("Tallet %d forekommer %d antall ganger i arrayet.\n", k, antall);
}

// OPPGAVE 3b
void sorter(int *A, int n){
    int tmp;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(A[i] < A[j]){
                tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }
}

//OPPGAVE 3c
void majoritetselement(int *A, int n){
    int maxTelle = 0;
    int index = -1;
    for(int i = 0; i < n; i++){
        int telle = 0;
        for(int j = 0; j < n; j++){
            if(A[i] == A[j]){
                telle++;
            }
        }
    if(telle > maxTelle){
        maxTelle = telle;
        index = i;
    }
    }
    if(maxTelle > n/2){
        printf("%d\n", A[index]);
    }
    else
    printf("Array har ikke majoritetselement, noob\n");
}

int main(){
    int A[] = {5, 3, 5, 5, 8, 2, 5, 7, 5, 2, 8, 5, 5, 9, 7, 5, 3, 5, 5};
    float str = sizeof(A)/sizeof(A[0]);

    printf("Størrelse på array: %d\n", (int)str);

    printf("Array før sorter: ");
    for(int i = 0; i < str; i++){
        printf("%d, ", A[i]);
    }
    printf("\n");

    sorter(A, str);

    printf("Array etter sorter: ");
    for(int i = 0; i < str; i++){
        printf("%d, ", A[i]);
    }
    printf("\n");

    printf("Majoritetselementet i A er: ");
    majoritetselement(A, str);

    forekommer(A, str, 5);

    return 0;
}


/*
OPPGAVE 4


*/