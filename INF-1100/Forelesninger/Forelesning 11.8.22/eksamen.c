eksamen 2018, høst


/*
OPPGAVE 2:
2a 
1) 2
2) 5

2b 
hvor mange ganger b forekommer i a


OPPGAVE 3:
3a 
int forekommer (int *A, int n, in k){
    int antall = 0;
    for( in i = 0; i < n; i++){
        if(A[i] == k)
        antall ++;
    }
    return antall;
}

3b
void swap(int *A, int index1, int index2){
    int temp = A[index2];
    A[index2] = A[index1];
    A[index1] = temp;
}

void sorter (int *A, int n){
    int sorted = 1;
    while(!sorted){
        for(int i = 0; i < n; i++){
            if(A[i] < A[i+1]){
                // Antar vi har en funksjon "swap" som bytter om to elementer
                swap(A, i, i+1);
                sorted = 0;
            }
        }
    }
}

3c
int majoritetselement (int *A, int n){
    for(int i = 0; i < n; i++){
        if(forekommer(A, n, A[i]) > n/2){
            return 1;
        }
    }
}



OPPGAVE 4:
4a 
int kontroll(list_t *spor, list_t *fasit){
    kontrollelement_t *besokt;
    kontrollelement_t *svar;

    list_iterator_t *besokiterator = list_createiterator(spor);
    //Eksmepel på feilsøking:
    if(besokiterator == NULL){
        return -1;
    }
    
    list_iterator_t *svariterator = list_createiterator(fasit);

    besok = list_next(besokiterator);
    svar = list_next(svariterator);

    while(besok != NULL && svar != NULL){
        if(besok->kode != svar->kode){
            return 0;
        }
        besok = list_next(besokiterator);
        svar = list_next(svariterator);
    }
    return 1;
}

4b
double tid(list_t *spor){
    double total = 0;
    list_iterator_t *besokiterator = list_createiterator(spor);
    kotrollelement_t *post;
    while(post = list_next(besokiterator)){
        total += post->strekktid;
    }
    return total;
}

4c
Går gjennom listen godkjente
kaller tid per deltager
finner korteste tid
returnerer korteste tid

*/