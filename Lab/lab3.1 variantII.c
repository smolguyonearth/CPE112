#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void insertBegin(node **start){
    node *newNode;
    int val;

    // printf("Enter data: ");
    scanf("%d", &val);
    newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = *start;
    *start = newNode;
}

void insertEnd(node **start){
    node *newNode, *ptr;
    int val;

    // printf("Enter Data: ");
    scanf("%d", &val);
    newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    // ptr = *start;
    // while(ptr->next != NULL)
    //     ptr = ptr->next;
    // ptr->next = newNode; 

    if (*start == NULL) {
        *start = newNode; 
    } else {
        ptr = *start;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
    }

}

// void printList(node *start) {
//     node *current = start;

//     while (current != NULL) {
//         printf("%d ", current->data);
//         current = current->next;
//     }
//     printf("\n");
// }

void printList(node *start) {
    if (start == NULL) {
        return;
    }

    printList(start->next);
    printf("%d ", start->data);
}

int main(){
    int n;
    scanf("%d", &n);
    int choice;
    scanf("%d", &choice);
    node *start = NULL;
    if(choice == 1){
        for(int i=0; i < n; i++){
            insertEnd(&start);
        }
        if (n != 0)
            printList(start);
        else
            printf("\nInvalid");
    }
    else if(choice == 2){
        for(int i=0; i < n; i++){
            insertBegin(&start);
        }
        if (n != 0)
            printList(start);
        else
            printf("\nInvalid");
    }
    else
        printf("Invalid");
        return 0;
    return 0;
}