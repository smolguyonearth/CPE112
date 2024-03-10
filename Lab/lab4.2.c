//Nitis Jadipang 66070501020

// Stack as linked list

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void push(Node **topPtr, int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = val;
    newNode->next = *topPtr;
    *topPtr = newNode;
}

void pop(Node **topPtr) {
    if (*topPtr == NULL) {
        printf("empty\n");
        return;
    }
    Node *temp = *topPtr;
    printf("%d\n", temp->data);
    *topPtr = (*topPtr)->next;
    free(temp);
}

void top(Node *topPtr) {
    if (topPtr == NULL) {
        printf("empty\n");
        return;
    }
    printf("%d\n", topPtr->data);
}

int empty(Node *topPtr) {
    return topPtr == NULL ? 1 : 0;
}

int main() {
    Node *topPtr = NULL;
    char opt;
    int val;

    do {
    scanf(" %c", &opt);
        switch (opt) {
            case 'p':
                scanf("%d", &val);
                push(&topPtr, val);
                break;
            case 'o':
                pop(&topPtr);
                break;
            case 't':
                top(topPtr);
                break;
            case 'e':
                printf("%d\n", empty(topPtr));
                break;
            case 'q':
                // Free any remaining nodes
                // while (topPtr != NULL) {
                //     pop(&topPtr);
                // }
                break;
            default:
                printf("Invalid option\n");
        }
    } while (opt != 'q');

    return 0;
}
