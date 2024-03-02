#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct listnode listnode_t;

struct listnode {
    listnode_t  *next;
    void        *item;
};

struct list {
    listnode_t *head;
    int numitems;
};

// Bruke NULL til å vise til en tom liste
// Malloc/realloc/calloc = Sørge for at vi alltid har nok minne til å drive koden
// Malloc = allokerer noe til heapen, "malloc(sizeof(etelleranna))", slepp å legge det som neste i stacken
// Realloc = allokerer nytt minne, kan være annen størrelse
// Bruker peker til å vite hvor vi allokerer minne, og for å ha muligehet å hente akkurat det man vil ut av heapen
// head peker til starten av listen

// LES DÆ OPP PÅ MALLOC/ALLOC

// Det ligger et *item i hver node i listen
// hvis vi f.eks. skal fjerne item nr3, må vi iterere gjennom listen til vi finner item nr 3 
// Når vi går gjennom et array så itterer vi gjennom det, det finnes funksjoner for dette i C
// Når vi skal iterere gjennom en list, må vi lage en egen funksjon for dette siden C ikke har disse funksjonene
// Alle list-funksjonene våre skal sørge for at vi kan legge til og fjerne ting fra listen, og sørge for at vi ikke har minnelekasje
// og aldri går tom for minne å bruke.

// Har ikke ubegrenser minne i heapen, derfor må vi også slette noe av det vi jobber med
// free = frigjør minne, altså sletter det. fjerner koblingen til heapen

// addlast skal legge til en ny node bakerst i listen
// slutten av listen peker alltid til NULL, da vet vi når vi er på slutten av listen og kan legge til en ny node her






// Creates and returns a new and empty list 
list_t *list_create(void)
{
    list_t *list;
// Allocates the memory of the list we creates
        list = malloc(sizeof(list_t));
// Sets the head of the list
        list->head = NULL;
        list->numitems = 0;

        return list;
}


// Destroys the list and whatever in it
void list_destroy(list_t *list)
{
// Deletes the list from the allocated memory
    free(list);
}


// Adds a new item to the beginning of the list and replacec head
void list_addfirst(list_t *list, void *item)
{
// Allocating the memory of the node that is being added
    listnode_t *node = (listnode_t*) malloc(sizeof(listnode_t));
// Replaces the current head and makes a pointer to it
    node->item = item;
    node->next = list->head;
    list->head = node;
    list->numitems++;
}


// Adds a item to the end of the list and replaces NULL
void list_addlast(list_t *list, void *item)
{
   listnode_t * current;

   current = list;
// Checks if the list is empty
    if(current == NULL){
        current = list->head;
    }
// Checks the length of the list
    while(current->next != NULL){
        current = current->next;
    }
// Allocates the memory of the new node
   current->next = malloc(sizeof(listnode_t));
   current->next->item = item;

   list->numitems++;
}


// Goes through the list and removes a item from it
void list_remove(list_t *list, void *item)
{
    listnode_t *node, *current;

    node = NULL;
    current = list->head;
// Find the wished node in the list
    while(current->item != item){
        node = current;
        current = current->next;
    }
// Removes the node from the list
    if(current == list->head){
        list->head = list->head->next;
    }
    else{
        node->next = current->next;
    }

    list->numitems--;
}

// Returns the size of the list at a given time
int list_size(list_t *list)
{
    return list->numitems;
}

struct list_iterator {
    listnode_t *next;
    list_t *list;
};

// Creates a iterator to go through the lsit
list_iterator_t *list_createiterator(list_t *list)
{
    list_iterator_t *iter;
        iter = malloc(sizeof(list_t));
        iter->next = list->head;
        iter->list = list;
        return iter;

}

// Destroys the iterator
void list_destroyiterator(list_iterator_t *iter)
{
    free (iter);
}

// Iterates to the next item in the list
void *list_next(list_iterator_t *iter)
{
    void *item;
    item = NULL;
// Iterates through the list
    if(iter->next != NULL){
        item = iter->next->item;
        iter->next = iter->next->next;
    }
    return item;
}

// Pointing the iterator to the first item in the list
void list_resetiterator(list_iterator_t *iter)
{
    iter->next = iter->list->head;
}
