//Nitis Jadipang

// Ten to X

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

int items[MAX_STACK_SIZE];
int top = -1;

int isFull() {
    return top == MAX_STACK_SIZE - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int item) {
    if (isFull()) {
        printf("Stack is full\n");
        exit(EXIT_FAILURE);
    }
    items[++top] = item;
}

int pop() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return items[top--];
}

void convertToBase(int n, int base) {
    if (n < 0 || base < 2 || base > 36) {
        printf("invalid\n");
        return;
    }

    while (n != 0) {
        int remainder = n % base;
        push(remainder);
        n /= base;
    }

    while (!isEmpty()) {
        int digit = pop();
        if (digit < 10) {
            printf("%d", digit);
        } else {
            printf("%c", 'A' + (digit - 10));
        }
    }
    printf("\n");
}

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    convertToBase(n, x);
    return 0;
}
