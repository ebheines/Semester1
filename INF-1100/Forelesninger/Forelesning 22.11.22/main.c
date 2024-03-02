#include <stdio.h>
#include <stdlib.h>

// Dobbelpekere
// Voidpekere
// Dynamisk minneallokering
// Arrays
// Datatyper

// Bytter om to verdier i et array av heltall
void swap(int *a, int *b){
    int c = *b;
    *b = *a;
    *a = c;
}

// Printer ut alle heltallene i et gitt array
void printArray(int *arr, int lengde){
    printf("Tallene i arrayet: ");
    for(int i = 0; i < lengde; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Sorterer arrayet
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

int main(){
    //int tall[] = {1, 2, 3};
    int tall[3];
    tall[0] = 1;
    tall[1] = 2;
    tall[2] = 3;

    int lengde = sizeof(tall)/sizeof(tall[0]);

    void *andre_tall;
    andre_tall = calloc(sizeof(int), 100);
    printf("Size of int: %ld\n", sizeof(int));
    ((int *)andre_tall)[0] = 10;
    printf("andre_tall: %d\n", ((int*)andre_tall)[0]);
    
    printArray(tall, lengde);
    swap(tall, tall+1);
    printArray(tall, lengde);
    swap(tall+1, tall+2);
    printArray(tall, lengde);

    int antall_tall = 100;

    int *mangetall = malloc(sizeof(int) * antall_tall);
    for(int i = 0; i < antall_tall; i++){
        mangetall[i] = rand() % 1000;
    }

    int sorted = 0;
    while(!sorted){
        printArray(mangetall, antall_tall);
        sleep(1);
        sorted = 1;
        for(int i = 1; i < antall_tall; i++){
            if(mangetall[i-1] > mangetall[i]){
                swap(mangetall + 1, mangetall + i - 1);
            }
        }
    }

    sorter(mangetall, antall_tall);
    printf("Tallene etter å blitt sortert igjen: \n");
    printArray(mangetall, 100);

    int *massemange[10];

    for(int i = 0; i < 10; i++){
        int *midlertidige_tall = calloc(sizeof(int) * 10);
        massemange[i] = midlertidige_tall;
    }

}

void list_next(list_iterator_t *iter);

void *min_verdi = (void *)make_list();
list_next((list_iterator_t *) min_verdi);