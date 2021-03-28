#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* next;
    int element;
} Node;

Node* ls_init(int value) {
    Node * ls = (Node *) malloc(sizeof(Node));
    ls->element = value;
    return ls;
}

void add_node(Node * node, int value) {
    Node * ls = (Node *) malloc(sizeof(Node));
    ls -> element = value;
    node -> next = ls;
}

void list_delete(struct node** head, struct node* n) {
    
}

int main(int argc, char** argv) {
    Node* ls = ls_init(4);
    printf("%d\n", ls->element);
    add_node(ls, 3);
    Node* ls2 = ls -> next;
    printf("%d\n", ls2->element);
    return 0;
}