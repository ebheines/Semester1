#include <stdio.h>
#include <math.h>

typedef struct koordinat koordinat_t;
struck koordinat{
    int x;
    int y;
};

double gjennomsnitt (double *A, int n){
    float sum = 0;

    for(int i = 0; i < n; i++){
        sum += A[i];
    }
    return sum/n;
}

double standardavvik(double *A, int n){
    float root;
    float sum1 = gjennomsnitt(A, n);

    for(int i = 0; i < n; i++){
        root += pow((A[i]-sum1), 2);
    }

    return sqrt(root/n);
}

void sorter(double *A, int n){
    int i, j, tmp;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(A[i] < A[j]){
            tmp = A[j];
            A[j] = A[i];
            A[i] = tmp;
            }
        }
    }
}




int main(){
    double A[] = {3,2,8,4,10,6,7};
    int size = sizeof(A)/sizeof(A[0]);

    float sum = gjennomsnitt(A, size);

    printf("%f\n", sum);

    printf("Unsorted order of array: ");
    for(int i = 0; i < size; i++){
        printf("%f, ", A[i]);
    }
    printf("\n");


    sorter(A, size);
    printf("Sorted order of the array: ");
    for(int i = 0; i < size; i++){
        printf("%f, ", A[i]);
    }
    printf("\n");

    printf("Standardavviket er: ");
    float avviket = standardavvik(A, size);
    printf("%f\n", avviket);

    return 0;
}