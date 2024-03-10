#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void insertEnd(node **head){
    struct node *prev = NULL, *current = *head, *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void printList(struct node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main(){
    int n,val;
    scanf("%d", &n);

    node *head = NULL;
    node *tail = NULL;
    int choice;

    scanf("%d", &choice);

    for(int i=0; i < n; ++i){
        scanf("%d", &val);
        node *newNode = (node*)malloc(sizeof(node));
        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    if(n<1){
        printf("\nInvalid");
        return 0;
    }

    if(choice == 1){
        insertEnd(&head);
        printList(head);
    }
    else if (choice == 2){
        printList(head);
    }
    else
        printf("Invalid");

    return 0;
}