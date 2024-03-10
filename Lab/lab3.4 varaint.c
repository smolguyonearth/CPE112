#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} node;

void inputVal(node **head, int val) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->next = NULL;

    if (*head == NULL)
        *head = newnode;
    else {
        node *ptr = *head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newnode;
        newnode->prev = ptr;
    }
}

void deleteNode(node **head, int pos) {
    if (*head == NULL)
        return;

    node *ptr = *head;

    if (ptr->data == pos) {
        *head = ptr->next;
        if (ptr->next != NULL)
            ptr->next->prev = NULL;
        free(ptr);
    } else {
        while (ptr != NULL && ptr->data != pos)
            ptr = ptr->next;
        if (ptr == NULL)
            return;

        if (ptr->next != NULL) {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
        } else {
            ptr->prev->next = NULL;
            free(ptr);
        }
    }
}

void neightbor(node *head, int pos, char ans[][2][10], int n) {
    node *ptr = head;

    if (ptr->data == pos) {
        strcpy(ans[n][0], "NULL");
        if (ptr->next == NULL)
            strcpy(ans[n][1], "NULL");
        else
            sprintf(ans[n][1], "%d", ptr->next->data);
    } else {
        while (ptr != NULL && ptr->data != pos)
            ptr = ptr->next;
        if (ptr == NULL) {
            strcpy(ans[n][0], "none");
            strcpy(ans[n][1], "");
        } else if (ptr->next != NULL) {
            sprintf(ans[n][0], "%d", ptr->prev->data);
            sprintf(ans[n][1], "%d", ptr->next->data);
        } else {
            sprintf(ans[n][0], "%d", ptr->prev->data);
            strcpy(ans[n][1], "NULL");
        }
    }
}

void printNode(node *head) {
    node *ptr = head;
    if (head == NULL)
        printf("none\nnone");
    else {
        while (ptr->next != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }

        printf("%d \n", ptr->data);

        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->prev;
        }
    }
}

int main(void) {
    int n = 1, val;
    node *start = NULL;
    char choice[10], ans[100][2][10];

    while (1) {
        scanf("%s", choice);
        if (strcmp(choice, "END") == 0)
            break;

        scanf("%d", &val);

        if (strcmp(choice, "ADD") == 0)
            inputVal(&start, val);
        else if (strcmp(choice, "DEL") == 0)
            deleteNode(&start, val);
        else {
            neightbor(start, val, ans, n);
            n++;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 1)
                printf(" ");
            printf("%s", ans[i][j]);
            if (strcmp(ans[i][j], "none") == 0)
                break;
        }
        printf("\n");
    }

    printNode(start);

    return 0;
}