//Nitis Jadipang 66070501020

// Stack Array

#include<stdio.h>
#include <stdbool.h>

// #define MAX_SIZE 100000000 //too much, codern timeout

#define MAX_SIZE 10000

int top = -1; 
int stack[MAX_SIZE];

bool isFull() {
    return top == MAX_SIZE - 1;
}

bool isEmpty() {
    return top == -1;
}

int push(int val) {
    if (isFull()) {
        printf("Stack Overflow.\n");
        return 0; 
    }
    
    top++;
    stack[top] = val;
    
    return 1;
}

void show() {
    int i;
    
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return ;
    }
    
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow.\n");
        return 0;
    }
    
    top--;
    return 1;
}


int main() {
    int size;
    scanf("%d", &size);
    if (size <= 0) {// size <= 0
        printf("Please enter a positive number.\n");
        return 0;
    }
    
    int mode;

    while (1) {
        scanf("%d", &mode);
        
        if (mode == 1) {
            int val, check;
            scanf("%d", &val);
            check = push(val);
            
            if (check == 0) {
                break;
            }
        } else if (mode == 2) {
            int check;
            check = pop();
            
            if (check == 0) {
                break;
            }
        } else if (mode == 3) {
            show();
            break;
        } else if (mode == 4) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice.\n");
            break;
        }
    }
    
    return 0;
}
