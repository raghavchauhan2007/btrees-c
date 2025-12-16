#include <stdio.h>
#define MAX 100

int queue[MAX];
int rear = -1;

int isEmpty() {
    return rear == -1;
}

int isFull() {
    return rear == MAX-1;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue Full");
        return;
    }

    queue[++rear] = data;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Empty");
        return -1;
    }
    
    int front = queue[0];

    for(int i=0; i<rear; i++) {
        queue[i] = queue[i+1];
    }

    rear--;
    return front;
}

int peek() {
    if(isEmpty()) {
        printf("Queue is empty");
        return -1;
    }

    return queue[0];
}

int main() {
    enqueue(5);
    enqueue(8);
    enqueue(24);
    enqueue(12);
    enqueue(6);

    while (!isEmpty()) {
        printf("%d\n", dequeue());
    }

    return 0;
}