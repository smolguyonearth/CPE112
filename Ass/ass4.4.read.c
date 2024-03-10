#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE]; // Global stack array to hold characters
int top = -1; // Global variable to keep track of the top index of the stack

void push(char c) { // Function to push a character onto the stack
    if (top == MAX_SIZE - 1) { // Check if the stack is full
        printf("Stack Overflow\n"); // Print an error message if stack is full
        return; // Return from the function
    }
    stack[++top] = c; // Increment top and push the character onto the stack
}

char pop() { // Function to pop a character from the stack
    if (top == -1) { // Check if the stack is empty
        printf("Stack Underflow\n"); // Print an error message if stack is empty
        return -1; // Return an error value
    }
    return stack[top--]; // Pop the top character from the stack and decrement top
}

int precedence(char c) { // Function to determine precedence of operators
    if (c == '+' || c == '-') // Check for addition or subtraction
        return 1; // Return precedence 1
    else if (c == '*' || c == '/') // Check for multiplication or division
        return 2; // Return precedence 2
    else
        return 0; // Return 0 for other characters (operands)
}

void infixToPostfix(char *exp) { // Function to convert infix expression to postfix
    char postfix[MAX_SIZE]; // Array to hold the postfix expression
    int j = 0; // Index for postfix array

    for (int i = 0; exp[i] != '\0'; i++) { // Loop through each character in the infix expression
        if (isalnum(exp[i])) // Check if the character is alphanumeric (operand)
            postfix[j++] = exp[i]; // Append operand to postfix expression
        else if (exp[i] == '(') // Check if the character is an opening parenthesis
            push(exp[i]); // Push it onto the stack
        else if (exp[i] == ')') { // Check if the character is a closing parenthesis
            while (top != -1 && stack[top] != '(') // Pop operators from stack until '(' is found
                postfix[j++] = pop(); // Append popped operators to postfix expression
            if (top == -1) { // If '(' not found, expression is invalid
                printf("Invalid expression\n");
                return;
            }
            pop(); // Pop '(' from stack
        } else { // Character is an operator
            while (top != -1 && precedence(exp[i]) <= precedence(stack[top])) // Pop operators with higher or equal precedence from stack
                postfix[j++] = pop(); // Append popped operators to postfix expression
            push(exp[i]); // Push current operator onto stack
        }
    }

    while (top != -1) // Pop remaining operators from stack
        postfix[j++] = pop(); // Append popped operators to postfix expression

    postfix[j] = '\0'; // Null-terminate the postfix expression
    printf("%s", postfix); // Print the postfix expression
}

int main() {
    char exp[MAX_SIZE]; // Array to hold the infix expression
    printf("Enter infix expression: "); // Prompt user to enter infix expression
    scanf("%s", exp); // Read infix expression from user

    infixToPostfix(exp); // Convert infix to postfix and print the result

    return 0; // Return from main function
}
