//Nitis Jadipang 66070501020

// Circular table

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// void display(struct node *start){
//     struct node *ptr = start;
//     if (ptr == NULL){
//         printf("none\n");
//         return;
//     }

//     do {
//         printf("%d ", ptr->data);
//         ptr = ptr->next;
//     } while (ptr != start);
// }

void insert(struct node **start, int data){
    struct node *newNode, *ptr;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    if (*start == NULL) {
        *start = newNode;
        newNode->next = *start;
    } else {
        ptr = *start;
        while(ptr->next != *start)
            ptr = ptr->next;
        ptr->next = newNode;
        newNode->next = *start;
    }
}

void del(struct node **start, int pos){
    if (*start == NULL) {
        return;
    }
    
    struct node *current = *start;
    struct node *prev = NULL;
    int count = 0;

    while (current->next != current){
        count = 1;

        while(count != pos){
            prev = current;
            current = current->next;
            count++;
        }

        //Delete
        if (current == *start){
            *start = current ->next;
        }

        prev->next = current->next;

        struct node *temp = current;
        current = current->next;
        free(temp);
    }
    printf("%d\n", current->data);
    free(current);
    *start = NULL;
}

int main(){
    int n,pos;
    scanf("%d", &n);
    scanf("%d", &pos);
    
    struct node *head = NULL;
    for(int i=0; i<n; i++){
        int data;
        scanf("%d", &data);
        insert(&head, data);
    }
    // display(&head);
    del(&head, pos);
    return 0;
}
