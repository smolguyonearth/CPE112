//Nitis Jadipang 66070501020

// Linked list that can go back

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

void display(struct node **start){
    struct node *ptr = *start;

    if (ptr == NULL)
    {
        printf("none \nnone ");
    }

    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void reverse(struct node **start){
    struct node *ptr = *start;

    while (ptr->next != NULL){
        ptr = ptr->next;
    }

    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
}

void ADD(struct node **head, int data){
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

void DEL(struct node **start, int num){
    struct node *ptr;
    if(*start == NULL){
        return;
    }

    ptr = *start;
    while (ptr != NULL && ptr->data != num){
        ptr = ptr->next;
    }

    if(ptr == NULL){
        return;
    }

    if(ptr->prev != NULL) {
        ptr->prev->next = ptr->next;
    }
    else{
        *start = ptr->next;
    }

    if(ptr->next != NULL){
        ptr->next->prev = ptr->prev;
    }

    free(ptr);
}

void SCH(struct node **start ,int num){
    struct node *ptr;
    if(*start == NULL){
        return;
    }

    ptr = *start;
    while (ptr != NULL && ptr->data != num)
        ptr = ptr->next;
    if (ptr == NULL) {
        printf("none\n");
        return;
    }
    if(ptr->prev != NULL){
        printf("%d ", ptr->prev->data);
    }
    else{
        printf("NULL ");
    }

    if(ptr->next != NULL){
            printf("%d", ptr->next->data);
    }
    else{
        printf("NULL");
    }
}

int main(){
    int initial_size = 4;
    char *string = (char *)malloc(initial_size * sizeof(char));
    
    struct node *head = NULL;
    while(strcmp(string, "END") != 0){
        scanf("%s" ,string);
        if(strcmp(string, "ADD") == 0){
            int data;
            scanf("%d", &data);
            ADD(&head, data);
        }
        if(strcmp(string, "DEL") == 0){
            int num;
            scanf("%d", &num);
            DEL(&head, num);
        }
        if(strcmp(string, "SCH") == 0){
            int num;
            scanf("%d", &num);
            SCH(&head, num);
            printf("\n");
        }
    }
    display(&head);
    printf("\n");
    
    // Check if the list is not empty before calling reverse
    if (head != NULL) {
        reverse(&head);
    }
    
    free(string);
}
