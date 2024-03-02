#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// a structure to hold a comment
typedef struct {
  char username[16];  // usernames can be at most 16 chars
  char message[140];  // messages can be at most 140 chars
} twete_t;

// structure for a list node
typedef struct node node_t;
struct node {
  twete_t twete;      // node holds actual data
  struct node *next;  // pointer to next node in list 
};

// a pointer that will point to the start of my list
node_t *start;       

int main() {
  int n = 10;

  // I will use this to hold an address temporarily while modifying
  // the list
  node_t *tmp;

  // fills the list with n nodes, each containing a twete. you don't need to
  // modify this block of code, but you might look at it and think about how
  // the list works
  for (int i = 0; i < n; i++) {
    // allocate space for a new node
    tmp = calloc(1, sizeof(node_t));

    // write data into node
    sprintf(tmp->twete.username, "user_%d", i + 1);
    sprintf(tmp->twete.message, "funny_joke_%d", i + 1);

    // link the node in at start of list:
    //    start->[item_1]->NULL
    //  becomes 
    //    start->[item_2]->[item_1]->NULL
    //  etc.
    tmp->next = start;
    start = tmp;
  }




  // TODO: the line below writes out the first twete in the list. expand so
  // that you write out all twetes in the list. I provide an outline of how to
  // do it below; feel free to ignore if you want to puzzle it out for
  // yourself:
  //  i)   start with a pointer to the first twete, print this one with the
  //       call to printf below.
  //  ii)  update the pointer to point to the next item in the list by
  //       following the node->next pointer; print this one; repeat.
  //  iii) stop at the end of the list. the last next-pointer has value NULL;
  //       if you an error about segmentation fault, you have gone
  //       too far. 
  //
  //       segmentation fault means that you tried to access memory that you
  //       don't have access to, and it is most likely because you tried to
  //       access the memory at address 0 (aka NULL). you can check for a NULL
  //       pointer as you'd expect: if (ptr == NULL) printf("problems");

  while(tmp != 0){
    printf("%s -- %s\n", tmp->twete.username, tmp->twete.message);
    tmp = tmp->next;
  }

  // printf("%s -- %s\n", start->twete.username, start->twete.message);
  // printf("%s -- %s\n", start->next->twete.username, start->next->twete.message);
  // printf("%s -- %s\n", start->next->twete.username, start->next->twete.message);



  // TODO: extra credit: I create a new twete 0 here. insert it at the end of our
  // list, please. then print out the list contents again to make sure you got
  // it right.

  node_t *new = calloc(1, sizeof(node_t));
  sprintf(new->twete.username, "user_0");
  sprintf(new->twete.message, "funny_joke_0");
  



  // TODO: extra-extra credit: this program could be expanded in various ways.
  // try to remove nodes (remember to free the memory!!!), try to add a node in
  // the middle of the list, change the list to use the pointer to a twete
  // instead of storing the data directly, make functions that do add/remove,
  // etc. etc. I won't provide a solution for the extra-extra credit. Use
  // printf() actively to check that the list has the structure that you expect
}

