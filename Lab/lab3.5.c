//Nitis Jadipang 66070501020

// Circular Linked List

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insert(struct node** start, int data){
    struct node *newNode, *ptr;

    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *start;
    ptr = *start;

    if (*start == NULL) {
        newNode->next = newNode;
        *start = newNode;
        return;
    }

    while(ptr->next != *start)
        ptr = ptr->next;
    ptr->next = newNode;
    newNode->next = *start;
}

void delete(struct node** head, int key){
    if(*head == NULL)
        return;
    struct node* temp = *head;
    struct node* prev = NULL;

    while (temp->data != key) {
        if (temp->next == *head) {
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    if (temp == *head) {
        prev = *head;
        while (prev->next != *head)
            prev = prev->next;
        if (*head == (*head)->next)
            *head = NULL;
        else {
            prev->next = (*head)->next;
            *head = (*head)->next;
        }
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

void printList(struct node* head) {
    struct node* temp = head;

    if (head == NULL) {
        printf("Empty\n");
        return;
    }

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct node* head = NULL;
    char command;
    int data;

    while (1) {
        scanf(" %c", &command);

        if (command == 'I') {
            scanf("%d", &data);
            insert(&head, data);
        } else if (command == 'D') {
            scanf("%d", &data);
            delete(&head, data);
        } else if (command == 'E') {
            break;
        }
    }

    printList(head);

    return 0;
}