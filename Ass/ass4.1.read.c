#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

// Define the maximum size of the stack
#define MAX_STACK_SIZE 100

// Declare the array to hold stack elements and the index of the top element
int items[MAX_STACK_SIZE];
int top = -1;

// Function to check if the stack is full
int isFull() {
    return top == MAX_STACK_SIZE - 1; // Return true if top index equals the maximum size of the stack
}

// Function to check if the stack is empty
int isEmpty() {
    return top == -1; // Return true if top index equals -1, indicating an empty stack
}

// Function to push an item onto the stack
void push(int item) {
    if (isFull()) { // Check if the stack is full
        printf("Stack is full\n"); // Print an error message
        exit(EXIT_FAILURE); // Terminate the program
    }
    items[++top] = item; // Increment the top index and insert the item into the stack
}

// Function to pop an item from the stack
int pop() {
    if (isEmpty()) { // Check if the stack is empty
        printf("Stack is empty\n"); // Print an error message
        exit(EXIT_FAILURE); // Terminate the program
    }
    return items[top--]; // Decrement the top index and return the item from the stack
}

// Function to convert a number to the specified base
void convertToBase(int n, int base) {
    // Check for invalid inputs
    if (n < 0 || base < 2 || base > 36) {
        printf("invalid\n"); // Print 'invalid' if inputs are invalid
        return;
    }

    // Convert the number to the specified base
    while (n != 0) {
        int remainder = n % base; // Calculate the remainder
        push(remainder); // Push the remainder onto the stack
        n /= base; // Update n by dividing it by the base
    }

    // Print the result by popping elements from the stack
    while (!isEmpty()) {
        int digit = pop(); // Pop an element from the stack
        if (digit < 10) {
            printf("%d", digit); // Print the digit if it's less than 10
        } else {
            printf("%c", 'A' + (digit - 10)); // Print the corresponding character for digits greater than or equal to 10
        }
    }
    printf("\n"); // Print a newline character after printing the result
}

// Main function
int main() {
    int n, x; // Declare variables to store the input number and target base
    scanf("%d%d", &n, &x); // Read input values
    convertToBase(n, x); // Convert the number to the specified base
    return 0; // Return 0 to indicate successful execution
}
