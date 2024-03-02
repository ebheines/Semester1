#include <stdio.h>
#include <math.h>

/*
Oppgave 2a)
Variablene x, z og y er alle variabler som er representert i koden og i minnet, men de alle er representert på forskjellige måter. x er representert 
som en integer, altså en enkel heltall verdi. y er en string av characters med en pointer til y. Da er hele "128" representert et sted i minnet. z er et array
som inneholder 1, 2 og 8.

Oppgave 2b)
64 vil printes når vi kjører programmet. Dette er fordi "y[0]" ikke viser til noen verdi siden vi har representert y med en pointer og ikke []. Character 1 
er heller ikke det samme som integer 1, de har 2 forskjellige verdier som vi kan se i ASCII tabellen. 64 skrives ut siden vi kjører x/z[0], x = 128 og z[1] = 2, 
128/2=64. 
*/


// Oppgave 3a)
double gjennomsnitt(double *A, int n){
    double sum = 0;

    for(int i = 0; i < n; i++){
        sum += A[i];
    }
    return sum/n;
}

// Oppgave 3b)
// double standardavvik(double *A, int n){
    // double root = 0;
    // double sum = gjennomsnitt(A, n);
// 
    // for(int i = 0; i < n; i++){
        // root += ((A[i]-sum)*(A[i]-sum));
    // }
    // return sqrt(sum/n);
// }

// Oppgave 3c)
void sorter(float *A, int n){
    int tmp;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(A[i] > A[j]){
                tmp = A[j];
                A[j] = A[i];
                A[i] = tmp;
            }
        }
    }
}

void printArray(double *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d - ", (int)A[i]);
    }
}

int main(){
double A[] = {4, 2, 3, 5, 6, 1, 7, 5, 8, 9};
printArray(A, 10);
printf("\n");

double gs = gjennomsnitt(A, 10);
printf("Gjennomsnittet er: %f\n", gs);
}



// Oppgave 4a)
/*
void addereKoordinat(list_t *list, koordinat_t *koordinat){
    list_iterator_t *iter = list_createiterator(list);


}
*/