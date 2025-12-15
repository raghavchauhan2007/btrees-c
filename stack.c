#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}node;

node* createNode(int data) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

node* head = NULL;

int isEmpty() {
    return head == NULL;
}

void push(int data) {
    node* newNode = createNode(data);

    if(isEmpty()) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

int pop() {
    if (isEmpty()) {
        return -1;
    }

    node* temp = head;
    int top = head->data;
    head = head->next;
    free(temp);
    return top;
}

int peek() {
    if (isEmpty()) {
        return -1;
    }

    return head->data;
}

int main() {
    push(5);
    push(1);
    push(8);
    push(24);
    push(15);

    while (!isEmpty()) {
        printf("%d\n", pop());
    }

    return 0;
}