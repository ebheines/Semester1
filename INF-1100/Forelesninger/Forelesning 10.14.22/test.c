#include <stdio.h>

int main(){
  /*
    FILE *min_fil = fopen("min_fil", "r");
    char tekst[100];
    fread(tekst, 1, 20, min_fil);
    printf("%s\n", tekst);

*/

    FILE *file1 = fopen("file1", "r");
    char tekst1[1000];
    fread(tekst1, 1, 200, file1);
    printf("Read from file1:\n%s\n", tekst1);

    printf("------------------\n");

    FILE *file2 = fopen("file2", "r");
    char tekst2[1000];
    fread(tekst2, 1, 200, file2);
    printf("Read from file2:\n%s\n", tekst2);

}