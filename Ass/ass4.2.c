//Nitis Jadipang 66070501020

// Palindrome checker

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

char items[MAX_STACK_SIZE];
int top = -1;

void push(char item) {
    if (top == MAX_STACK_SIZE - 1) {
        printf("Stack is full\n");
        exit(EXIT_FAILURE);
    }
    items[++top] = item;
}

char pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return items[top--];
}

int isPalindrome(char *str) {
    int length = strlen(str);
    int i;

    for (i = 0; i < length / 2; i++) {
        push(str[i]);
    }

    for (i = length / 2 + (length % 2); i < length; i++) {
        if (str[i] != pop()) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Palindrome
}

int main() {
    char input[MAX_STACK_SIZE];
    scanf("%s", input);

    if (isPalindrome(input)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}
