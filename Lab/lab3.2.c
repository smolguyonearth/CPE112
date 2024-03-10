//Nitis Jadipang 66070501020

// Before or After Insertion ?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

void displayList(struct node **start) // display sublist
{
    struct node *ptr = *start; // assign *ptr to pointer to head of the list

    if (ptr == NULL) // if ptr is null
    {
        printf("None");
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

void insertBefore(struct node **start, int num, int val){
    struct node *newNode, *ptr;
    // int val;

    // scanf("%d", &val);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    ptr = *start;

    
    while(ptr != NULL && ptr->data != num)
        ptr = ptr->next;

    if (ptr == NULL) {
        // Value not found, do nothing
        free(newNode);
        return;
    }

    newNode->next = ptr;
    newNode->prev = ptr->prev;
    // ptr->prev->next = newNode;
    // ptr->prev = newNode;
    
    if (ptr->prev != NULL) {
        ptr->prev->next = newNode;
    } else {
        *start = newNode; // Update start if inserting at the beginning
    }
    ptr->prev = newNode;
}

void insertAfter(struct node **start, int num, int val){
    struct node *newNode, *ptr;
    // int val;

    // scanf("%d", &val);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    ptr = *start;

    while(ptr != NULL && ptr->data != num)
        ptr = ptr->next;
        
    if (ptr == NULL) {
        // Value not found, do nothing
        free(newNode);
        return;
    }

    newNode->next = ptr->next;
    newNode->prev = ptr;
    
    // ptr->prev->next = newNode;
    // ptr->prev = newNode;

    // if (ptr->prev != NULL) {
    //     // ptr->prev->next = newNode;
    //     ptr->next->prev = newNode;
    // } else {
    //     // *start = newNode; // Update start if inserting at the beginning
    //     newNode->next = NULL;
    // } 

    if (ptr->next != NULL) {
        // newNode->next = ptr->next;
        ptr->next->prev = newNode;
    }
    // else {
    //     newNode->next = NULL; 
    // }

    ptr->next = newNode;
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
    // displayList(&head);

    char opt = ' ';
    int num;
    int val;

    while(1){
        scanf(" %c", &opt);
        if (opt == 'E'){
            break;
        }
        scanf(" %d %d", &num, &val);
        // if (strcmp(opt, "A") == 0) {
        //     insertAfter(&head, num);
        // }
        // else if (strcmp(opt, "B") == 0) {
        //     insertBefore(&head, num);
        // }
        if (opt == 'A'){
            insertAfter(&head, num, val);
        }
        else if (opt == 'B'){
            insertBefore(&head, num, val);
        }
    }

    // scanf(" %c %d %d", &opt, &num, &val);

    // if (opt == 'A'){
    //     insertAfter(&head, num, val);
    // }
    // else if (opt == 'B'){
    //     insertBefore(&head, num, val);
    // }

    displayList(&head);
}