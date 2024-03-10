#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the circular linked list
void insert(struct Node** head_ref, int data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    // Set data and next pointer of new node
    new_node->data = data;
    new_node->next = *head_ref;

    // If the list is empty, make new node as head
    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }

    // Otherwise, traverse the list to find the last node
    while (last->next != *head_ref)
        last = last->next;

    // Connect the last node to the new node
    last->next = new_node;

    // Make the new node as the last node
    new_node->next = *head_ref;
}

// Function to delete the first occurrence of a node with given data from the circular linked list
void deleteNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL)
        return;

    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // Find the node with the key to be deleted
    while (temp->data != key) {
        // If we reach the head node again, key not found
        if (temp->next == *head_ref) {
            printf("%d not found in the list.\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    // If the node to be deleted is the head node
    if (temp == *head_ref) {
        prev = *head_ref;
        while (prev->next != *head_ref)
            prev = prev->next;
        if (*head_ref == (*head_ref)->next)
            *head_ref = NULL;
        else {
            prev->next = (*head_ref)->next;
            *head_ref = (*head_ref)->next;
        }
    } else {
        // Unlink the node from linked list
        prev->next = temp->next;
    }

    free(temp);
}

// Function to print circular linked list starting from given node
void printList(struct Node* head) {
    struct Node* temp = head;

    // If list is empty, print "Empty"
    if (head == NULL) {
        printf("Empty\n");
        return;
    }

    // Traverse the list starting from head
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    char command;
    int data;

    // Read commands until 'E' is encountered
    while (1) {
        scanf(" %c", &command); // Added space before %c to consume whitespace characters

        // Insert command
        if (command == 'I') {
            scanf("%d", &data);
            insert(&head, data);
        }
        // Delete command
        else if (command == 'D') {
            scanf("%d", &data);
            deleteNode(&head, data);
        }
        // End command
        else if (command == 'E') {
            break;
        }
    }

    // Display the circular linked list
    printList(head);

    return 0;
}
