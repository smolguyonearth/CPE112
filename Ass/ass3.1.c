//Nitis Jadipang 66070501020

// It's Sorting Time

#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *next;
    int ID;
    int score;
};
void insert(struct node **head, int id, int score){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->ID = id;
    newNode->score = score;
    newNode->next = NULL;

    if(*head==NULL){
        *head = newNode;
    }
    else{
        struct node *ptr = *head;
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void sortscore(struct node **head){
    struct node *current = *head;
    struct node *index = NULL;

    int tempID, tempScore;

    if(*head == NULL){
        return;
    }else{
        while(current != NULL){
            index = current->next;

            while(index != NULL){
                if(current->score > index->score){
                    tempScore = current->score;
                    current->score = index->score;
                    index->score = tempScore;

                    tempID = current->ID;
                    current->ID = index->ID;
                    index->ID = tempID;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void sortID(struct node **head) {
    struct node *current = *head;
    struct node *index = NULL;
    int tempID, tempScore;

    if (*head == NULL) {
        return; 
    } else {
        while (current != NULL) {
            index = current->next;

            while (index != NULL) {
                if (current->ID > index->ID) {
                    tempID = current->ID;
                    current->ID = index->ID;
                    index->ID = tempID;

                    tempScore = current->score;
                    current->score = index->score;
                    index->score = tempScore;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void displayscore(struct node **start) // display sublist
{
    struct node *ptr = *start; // assign *ptr to pointer to head of the list

    if (ptr == NULL) // if ptr is null
    {
        printf("None");
    }

    while (ptr != NULL) // loop until ptr is null
    {
        // printf("%d ", ptr->ID); // print value of current node
        printf("%d ", ptr->score); // print value of current node
        ptr = ptr->next;          // move ptr to next node
    }
}

int main(){
    struct node *head = NULL;
    int n; 
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int id,score;
        scanf("%d %d", &id, &score);
        insert(&head, id, score);
    }

    int opt;
    scanf("%d", &opt);

    if (opt == 0){
        sortID(&head);
        displayscore(&head);
    }
    else if (opt == 1){
        sortscore(&head);
        displayscore(&head);
    }
}