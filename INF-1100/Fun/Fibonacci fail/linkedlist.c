#include <stdio.h>
#include <stdlib.h>


struct node{
    int value;
    struct node* next;
};
typedef struct node node_t;

void print_list(node_t *head){
    node_t *temp = head;

    while(temp != NULL){
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

node_t *create_new_node(int value){
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

node_t * insert_at_head(node_t **head, node_t *node_to_insert){
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

void insert_after_node(node_t *node_to_insert_after, node_t* newnode){
    newnode->next = node_to_insert_after->next;
    node_to_insert_after->next = newnode;
}

node_t *find_node(node_t *head, int value){
    node_t *temp = head;
    while(temp != NULL){
        if(temp->value == value) 
        return temp;
        temp = temp->next;
    }
    return NULL;
}


int main(){
    node_t *head = NULL;
    node_t *temp;

    for(int i=0; i < 12; i++){
        temp = create_new_node(i);
        head = insert_at_head(&head, temp);
    }

    insert_after_node(head, create_new_node(75));

    print_list(head);

    return 0;
}