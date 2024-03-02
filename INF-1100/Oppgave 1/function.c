#include <stdio.h>
#include <string.h>

// Signaturer for hver av funksjonene
void sammelign_verdi(int x, int y);
void minTrekant (int a, int b, int rader);
int mittPrimtall (int nummer, int primTall);
void mittTall (int startTall, int sluttTall, int n);
void myLog2n (int c, int d);
void stringReverse (int a1, int b1, int teller);


int main(){
    int oppgave;
    printf("Hvilken oppgave vil du vise (1-6):  ");
    scanf("%d", &oppgave);

    // Bruker switch til å kunne velge hvilken oppgave som skal vises i Terminal
    switch (oppgave) {

case 1:
    printf("I oppgave 1 skal du legge inn 2 verdier for x og y. Koden vil da fortelle den hvilken av verdiene som er høyest eller om de eventuelt har samme verdi.\n\n");
    int x, y;
    sammelign_verdi(x, y); 
    return 0;
break;

case 2:
    printf("I oppgave 2 skal du skrive inn antall rader du ønsker i en trekant som koden vil skape.\n\n");
    // Definer mengdene for a, b og rader(antall rader vi skal ha i trekanten)
    int a, b, rader;
    minTrekant(a, b, rader);
break;

case 3:
    printf("I oppgave 3 skal du legge inn 2 verdier for et nummer og et primtall. Koden vil printe 1 eller 0, utifra om primtallet faktisk er et primtall til tallet du har valgt. 1 = sant og 0 = usant.\n\n");
    //Definer nummer og primTall
    int nummer, primTall;
     //Legg inn et verdi for nummeret du skal sjekke primtall på
    printf("Velg et tall:  ");
    scanf("%d", &nummer);

    //Legg inn verdi for det lurer på er et primtall i det originale nummeret
    printf("\nVelg primtall:  ");
    scanf("%d", &primTall);

    //Kjører koden for å finne primtallet til den originale tallet
    mittPrimtall(nummer, primTall);
    if (mittPrimtall (nummer, primTall) == 0) {
    printf("\n0\n");
    }
    else {
    printf("\n1\n");
    }
break;

case 4:
    printf("I oppgave 4 vil du legge inn starttall og sluttall i en tallrekke. Funksjonen vil så fortelle om hvert tall er partall/oddetall, og om 5 er et primtall.\n\n");
    int startTall, sluttTall, n;
    mittTall(startTall, sluttTall, n);

return 0;
break;

case 5:
    printf("I oppgave 5 legger du inn en verdi for n i 'log2n' og koden vil da gi deg svaret på logaritmen. Svaret er potensen som skal stå over 2 for å få nærmeste og høyeste verdi for tallet du valgte.\n\n");
    int c;
    int d;

myLog2n(c, d);
return 0;
break;

case 6:
    printf("I oppgave 6 legger du inn en string - eller et sammenhengende ord - som koden vil reversere og printe for deg.\n\n");
    int a1;
    int b1;
    int teller;
    stringReverse(a1, b1, teller);
break;
return 0;
    }
}






// OPPGAVE 1
void sammelign_verdi(int x, int y){  
      //Printer og ber om å få satt inn en verdi for x
    printf("Velg en verdi for x:  ");
    scanf("%d", &x);

    //Printer og ber om å få satt inn en verdi for y
    printf("Velg en verdi for y:  ");
    scanf("%d", &y);
    
    //If-statement for betingelsen "x er større enn y"
    if (x<y) {
    printf("y har den høyeste verdi");
    printf("\n");
    }

    //else if-statement for betingelsen "x er lik y"
    else if (x==y) {
    printf("x og y har samme verdi");
    printf("\n");
    }

    //else-statement for betingelsen "y er større enn x"
    else {
    printf("x har den høyeste verdien");
    printf("\n");
    }
}

//OPPGAVE 2
void minTrekant (int a, int b, int rader){
     //Legger inn verdi for antall rader i trekanen
    printf("Velg antall rader for din trekant:  ");
    scanf("%d", &rader);

    //Skaper trekanten etter verdien som er satt for "rader"
    for (a = 1; a <= rader; a++) { // verdien for a øker helt til den er lik verdien til rader, som vi har gitt i terminalen
    for (b = 1; b <= a; b++) {  //verdien for b er antall rader vi lager i terminalen, b gjør det samme som a, øker til de har samme verdi
    printf("* ");
    }

    //Printer trekanten
    printf("\n");
    }
}

//Oppgave 3
int mittPrimtall (int nummer, int primTall){
    if (primTall != 0) {
        //Modulus operator brukes for å finne ut om primTall er et primtall i nummer
        if (nummer % primTall == 0) {
        return 1; //True, primTall er faktisk er primtall i nummer
        }
        else {
        return 0; // False, primTall er ikke et primtall i nummer
        }

    }
    return 2; // For å avslutte funksjonen, men har allerde brukt 'return 0' og 'return 1'
}

//Oppgave 4
void mittTall (int startTall, int sluttTall, int n){
    //Velg et starttall
    printf("Velg et starttall: ");
    scanf("%d", &startTall);

    //Velg et sluttall
    printf("Velg et sluttall: ");
    scanf("%d", &sluttTall);

    //While-loop som lager tallrekken fra starttallet til sluttallet
    while (startTall <= sluttTall) {
    //Bruker if/else for å bestemme om tallene er odde- eller partall
    if (startTall % 2 == 0) {
    printf("%d er et parttall ", startTall);
    }
    else if (startTall % 2 != 0) {
    printf("%d er et oddetall ", startTall);
    }

    //Bruker if/else og funksjonen fra oppgave 3 til å finne ut om 5 er et primtall i tallene
    if (mittPrimtall(startTall, 5) == 1) {
    printf("og 5 er et primtall i %d\n", startTall);
    }
    else if (mittPrimtall(startTall, 5) == 0) {
    printf("og 5 er ikke et primtall i %d\n", startTall);
    }
    startTall++;
    }
}

//OPPGAVE 5
void myLog2n (int c, int d) {
    d = 0;
    // Velger et tall
    printf("Velg et tall: ");
    scanf("%d", &c);

    // Bruker while-loop til å utføre en bit shift operation, som igjen hjelper oss med å finne den mest betydningsfulle biten
    while (c >= 1) {
    c = c >> 1;
    d++;
    }
    // Viser i output posisjonen til den mest betydningsfulle biten
    printf("%d\n", d-1);
}

//OPPGAVE 6
void stringReverse (int a1, int b1, int teller){
    //Definerer 2 strings, en for det vi skriver inn og en for å reversere den først.
    char string[1000], stringRev[1000];
    teller = 0;

    //Scanner det vi skriver i terminal for å reversere det
    printf("Velg et ord som string:  ");
    scanf(" %[^\n]s", string);
    printf("\nString-en før det blir reversert: %s", string);

    //Bruker while-funkjsonen til å finne lengden på stringen
    while (string[teller] != '\0') {
    teller++;
    }
    b1 = teller - 1;

    //Bruker for-funksjonen for å reversere stringen gjennom å bytte 
    for (a1 = 0; a1 < teller; a1++) {
    stringRev[a1] = string[b1];
    b1--;
    }

    printf("\nString-en etter det blir reversert: %s\n", stringRev);
}
