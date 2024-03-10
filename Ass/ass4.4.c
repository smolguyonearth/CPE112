//Nitis Jadipang 66070501020

// Infix to Postfix

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char c) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

void infixToPostfix(char *exp) {
    char postfix[MAX_SIZE];
    int j = 0;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (isalnum(exp[i]))
            postfix[j++] = exp[i];
        else if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            if (top == -1) {
                printf("Invalid expression\n");
                return;
            }
            pop();
        } else {
            while (top != -1 && precedence(exp[i]) <= precedence(stack[top]))
                postfix[j++] = pop();
            push(exp[i]);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
    printf("%s", postfix);
}

int main() {
    char exp[MAX_SIZE];
    // printf("Enter infix expression: ");
    scanf("%s", exp);

    infixToPostfix(exp);

    return 0;
}