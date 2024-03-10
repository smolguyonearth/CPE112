//Nitis Jadipang 66070501020

//Where to Delete?

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

void deleteFirst(struct node **start){
    struct node *ptr;
    if(*start == NULL){
        printf("none\n");
        return;
    }
    
    ptr = *start;
    *start = (*start)->next;
    if (*start != NULL) {
        (*start)->prev = NULL;
    }
    free(ptr);
    // ptr = *start;
    // while(ptr->next != *start)
    //     ptr = ptr->next;
    // ptr->next = (*start)->next;
    // free(*start);
    // *start = ptr->next;
}


void deleteLast(struct node **start){
    struct node *ptr;
    if(*start == NULL){
        printf("none\n");
        return;
    }

    ptr = *start;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->prev->next = NULL;
    free(ptr);

    // ptr = *start;
    // while(ptr->next != *start){
    //     prePtr = ptr;
    //     ptr = ptr->next;
    // }
    // prePtr->next = *start;
    // free(ptr);
}

void deleteNode(struct node **start, int num){
    struct node *ptr;
    if(*start == NULL){
        printf("none\n");
        return;
    }

    ptr = *start;
    while (ptr != NULL && ptr->data != num)
        ptr = ptr->next;
    
    if (ptr == NULL) {
        // Node with the specified value not found
        return; // Skip deletion
    }
    
    if(ptr->prev != NULL) {
        ptr->prev->next = ptr->next;
    }
    else {
        *start = ptr->next;
    }

    if(ptr->next != NULL){
        ptr->next->prev = ptr->prev;
    }

    free(ptr);
}


void displayList(struct node **start) // display sublist
{
    struct node *ptr = *start; // assign *ptr to pointer to head of the list

    if (ptr == NULL) // if ptr is null
    {
        printf("none");
    }

    while (ptr != NULL) // loop until ptr is null
    {
        printf("%d ", ptr->data); // print value of current node
        ptr = ptr->next;          // move ptr to next node
    }
}

void insertNodeEnd(struct node **head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct node *ptr = *head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->prev = ptr;
    }
}


int main(){
    int n;
    scanf("%d", &n);
    struct node *head = NULL;

    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        insertNodeEnd(&head, data);
    }
    char opt;
    while(1){
        scanf(" %c", &opt);
        if(opt == 'E'){
            break;
        }
        int num;
        scanf("%d", &num);

        if(opt == 'F'){
            deleteFirst(&head);
        }
        else if(opt == 'L'){
            deleteLast(&head);
        }
        else if(opt == 'N'){
            deleteNode(&head, num);
        }
    }
    displayList(&head);
}