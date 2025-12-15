#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}node;

node *head, *newNode, *currNode;

void addFirst(int data) {
    newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = 0;
    
    // if(head == 0) {
    //     head = currNode = newNode;
    //     return;
    // }

    newNode->next = head;
    head = newNode;
}

void addLast(int data) {
    newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = 0;
    
    if(head == 0) {
        head = currNode = newNode;
    }

    currNode = head;

    while(currNode->next != 0) {
        currNode = currNode->next;
    }

    currNode->next = newNode;
}

int main() {
    head = 0;
    addFirst(5);
    addFirst(6);
    addFirst(8);
    addFirst(10);
    addFirst(55);
    addFirst(2);
    addLast(4);

    node* i = head;

    while(i != 0) {
        printf("%d\n", i->data);
        i = i->next;
    }

    return 0;
}