//Nitis Jadipang 66070501020
#include <stdio.h>
#include <stdlib.h>

int size;
int* queue;

int front = -1, rear = -1;

void insertq(int val){
    if((front == 0 && rear == size-1) || (front == rear+1)){
        printf("Queue is full!!\n");
        return;
    }
    rear++;
    if(rear >= size){
        rear = 0;
    }
    queue[rear] = val;
    if(front == -1){
        front = 0;
    }
}

void dequeue(){
    if(front == -1){
        printf("Queue is empty!!\n");
        return;
    }
    printf("%d\n",queue[front]);
    if(front == rear){
        front = rear = -1;
    }else{
        front++;
        if(front >= size){
            front = 0;
        }
    }
}

void show(){
    if(front == -1){
        printf("Queue is empty!!\n");
        return;
    }
    printf("Front: %d\n",front);
    printf("Items:");
    while(1){
        if(front == rear){
            printf(" %d \n",queue[front]);
            break;
        }
        printf(" %d",queue[front]);
        front++;
        if(front >= size){
            front = 0;
        }
    }
    printf("Rear: %d\n",rear);
}

int main(void){
    int n;
    scanf("%d",&n);
    size = n;
    queue = (int*)malloc(sizeof(int)*n);
    char c;
    while(1){
        scanf(" %c",&c);
        if(c == 'E'){
            break;
        }else if(c == 'I'){
            int val;
            scanf(" %d",&val);
            insertq(val);
        }else if(c == 'D'){
            dequeue();
        }else if(c == 'S'){
            show();
        }
    }
}