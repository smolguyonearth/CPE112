//Nitis Jadipang 66070501020

// Linked Lists Insertion

#include <stdio.h>
#include <stdlib.h>

struct node
{
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

void insertNodeBegin(struct node **head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertNodeEnd(struct node **head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
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
    }
}

int main(){
    int n; 
    scanf("%d", &n);


    int choice;
    scanf("%d", &choice);

    if(n <= 0){
        printf("Invalid");
        return 0;
    }

    if(choice != 2 && choice != 1){
        printf("Invalid");
        return 0;
    }
    struct node *head = NULL;

    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);

        if (choice == 1)
        {
            insertNodeBegin(&head, data);
        }
        else if (choice == 2)
        {
            insertNodeEnd(&head, data);
        }
    }

    displayList(&head);

    return 0;
}