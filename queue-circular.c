#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int rear = -1;
int front = -1;

int isEmpty() {
    return rear == -1 && front == -1;
}

int isFull() {
    return (rear+1)%SIZE == front; 
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue Full\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear = (rear+1)%SIZE;
    queue[rear] = data;
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Empty\n");
        return -1;
    }
    
    int result = queue[front];

    if (rear == front) {
        rear = front = -1;
    }

    else {
        front = (front+1)%SIZE;
    }

    return result;
}

int peek() {
    if(isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }

    return queue[front];
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    printf("%d\n", dequeue());
    enqueue(6);
    printf("%d\n", dequeue());
    enqueue(7);

    while (!isEmpty()) {
        printf("%d\n", dequeue());
    }

    return 0;
}