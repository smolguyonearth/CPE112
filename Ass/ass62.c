#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arr[1000];
char stack[1000][1000];
int top = -1;

int op(char c){
    switch (c) {
        case '+':
        case '-':
        case '/':
        case '*':
            return 1;
    }
    return 0;
}

void push(char var[]){
    strcpy(stack[++top], var);
}

void pop(){
    top--;
}

int main(){
    scanf("%s", arr);
    
    for(int i = strlen(arr) - 1; i >= 0; i--){
        if(op(arr[i])){
            char num1[1000], num2[1000];
            strcpy(num1, stack[top]);
            pop();
            strcpy(num2, stack[top]);
            pop();
            char temp[1000] = "";
            strcat(temp, num1);
            strcat(temp, num2);
            char new[2];
            new[1] = '\0';
            new[0] = arr[i];
            strcat(temp, new);
            push(temp);
        } else {
            char new[2];
            new[1] = '\0';
            new[0] = arr[i];
            push(new);
        }
    }
    
    printf("%s", stack[top]);
    return 0;
}
