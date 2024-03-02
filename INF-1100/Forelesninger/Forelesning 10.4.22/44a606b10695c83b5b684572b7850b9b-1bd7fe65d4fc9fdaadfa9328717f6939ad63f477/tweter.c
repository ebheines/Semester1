#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// a structure to hold a twete
typedef struct {
  char username[16];   // usernames can be at most 16 chars
  char message[140];   // messages can be at most 140 chars
} twete_t;


// allocated space for one (1) twete
twete_t static_twete;

int main() {
  // set seed of random number generator based on current time
  srand(time(NULL));

  // generate a random number of twetes, more than 5, no more than 100
  int n_twetes = 5 + rand() % 95;

  // TODO: currently each new twete overwrites the previous
  // allocate an array that can hold n_twetes of twete_t structures
  // instead to make space to store all the twetes in an array that is
  // n_twetes long. 
  // hint: use functions calloc and sizeof
  


  // TODO: allocate space here
  twete_t *twete_array = calloc(n_twetes, sizeof(twete_t));

  // TODO: incoming twetes. should add to array instead of overwriting the
  // static location
  for (int i = 0; i < n_twetes; i++) {
    sprintf(twete_array[i].username, "user_%d", i);
    sprintf(twete_array[i].message, "funny_joke_%d", i);
  }

  // TODO: this currently prints only the last twete. modify so that it prints
  // all of the stored twetes, one after another
  for(int i = 0; i < n_twetes; i++){
  printf("%s -- %s\n", twete_array[i].username, twete_array[i].message);
 }
}
