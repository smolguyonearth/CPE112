//Nitis Jadipang 66070501020
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1002

typedef struct {
    char alpha;
    int pri;
} Node;

Node queue[MAX_SIZE];
int front = -1;
int rear = -1;

int inTheArray(char c, char *string, int size) {
    for (int i = 0; i < size; i++) {
        if (c == string[i]) {
            return 1;
        }
    }
    return 0;
}

void enqueue(Node newNode) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }

    int i;
    if (front == -1) {
        front = 0;
        rear = 0;
        queue[rear] = newNode;
        return;
    }

    for (i = rear; i >= 0; i--) {
        if (newNode.pri > queue[i].pri)
            queue[i + 1] = queue[i];
        else
            break;
    }

    queue[i + 1] = newNode;
    rear++;
}

void readQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%c", queue[i].alpha);
    }
}

int main() {
    char txt[MAX_SIZE];
    scanf(" %[^\n]", txt);

    for (int i = 0; txt[i]; i++) {
        Node newNode;
        newNode.alpha = txt[i];

        char vowels[] = "aeiouAEIOU";
        if (inTheArray(txt[i], vowels, sizeof(vowels) - 1)) {
            newNode.pri = 3;
        } else if (('a' <= txt[i] && txt[i] <= 'z') || ('A' <= txt[i] && txt[i] <= 'Z')) {
            newNode.pri = 1;
        } else {
            newNode.pri = 2;
        }

        enqueue(newNode);
    }

    readQueue();
    return 0;
}
