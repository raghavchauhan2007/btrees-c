#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX-1;
}

void push(int data) {
    if (isFull()) {
        printf("Stack is FULL\n");
        return;
    }

    stack[++top] = data;
}

int pop() {
    if (isEmpty()) {
        printf("Stack is Empty\n");
        return -1;
    }

    return stack[top--];
}

int peek() {
    if (isEmpty()) {
        printf("Stack is Empty\n");
        return -1;
    }

    return stack[top];
}

int main() {
    push(5);
    push(8);
    push(15);
    push(24);
    push(12);
    printf("%d\n", peek());

    while (!isEmpty()) {
        printf("%d\n", pop());
    }

    return 0;
}