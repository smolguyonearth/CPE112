//Nitis Jadipang 66070501020

// Parenthesis Checker

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

int top = -1; 
int stack[MAX_SIZE];

void push(char val) {
    top++;
    stack[top] = val;   
    // return 1; string shouldnt use int? perhabs
}

char pop() {
    if (top == -1) {
        return '\0';
        //becaue it is string
    }
    top--;
    return stack[top];
}

//check balance
bool balance(char* word){
    //reset top
    top = -1;

    for (long int i = 0; i < strlen(word); i++){
        char current = word[i];
        if (current == '(' || current == '{' || current == '[') {
            push(current);
        }
        else if (current == ')' || current == '}' || current == ']') {
        if (top == -1 || ((current == ')' && stack[top] != '(') || (current == '}' && stack[top] != '{') || (current == ']' && stack[top] != '['))){
            return false;
        }
        pop();
        }
    }

    return top == -1; //empty
}
int main(){
    char word[MAX_SIZE];
    scanf("%s", word);

    if (balance(word)) {
        printf("The string is balanced\n");
    } else {
        printf("The string is not balanced\n");
    }
    return 0;
}