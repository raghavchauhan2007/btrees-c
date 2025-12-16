#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}node;

node* head = NULL;
node* tail = NULL;

node* createNode(int data) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

int isEmpty() {
    return head == NULL && tail == NULL;
}

void enqueue(int data) {
    node* newNode = createNode(data);
    
    if(tail == NULL) {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

int dequeue() {
    if (isEmpty()) {
        printf("Empty Queue\n");
        return -1;
    }

    int front = head->data;
    node* temp = head;

    if(head == tail) {
        tail = NULL;
    }

    head = head->next;
    free(temp);
    return front;
}

int peek() {
    if (isEmpty()) {
        printf("Empty Queue\n");
        return -1;
    }

    return head->data;
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    while (!isEmpty()) {
        printf("%d\n", dequeue());
    }

    return 0;
}