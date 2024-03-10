//Nitis Jadipang 66070501020
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10000

typedef struct item{
    char song[1000];
    char artist[1000];
    int time;
} item;

item queue[MAX];
int rear = -1, front = -1;

void add(item val){
    if(rear == MAX-1){
        printf("\nOverflow: Queue is full");
        return;
    }
    else if (front == -1 && rear == -1)
        front = rear = 0;
    else
        rear++;
    queue[rear] = val;
}

// void play(){
//     if(front == -1 || front > rear){
//         printf("No song in the playlist\n");
//         return;
//     }
//     printf("Now playing: %s by %s\n", queue[front].song, queue[front].artist);
//     front++;
//     if(front > rear){
//         front = rear = -1; // Reset queue
//     }
// }
void play(){
    if(front == -1){
        printf("No songs in the playlist\n");
        return;
    }
    printf("Now playing: %s by %s\n", queue[front].song, queue[front].artist);
    if(front < rear) front++;
    else if(front == rear) front = rear = -1;
    else front = rear = -1;
}

void sum(){
    if(front == -1 || front > rear){
        printf("No songs in the playlist\n");
        return;
    }

    int total = 0;
    int temp_front = front;

    if(temp_front <= rear){
        printf("Songs in the playlist:\n");
    }

    while(temp_front <= rear){
        printf("%s by %s %d\n", queue[temp_front].song, queue[temp_front].artist, queue[temp_front].time);
        total += queue[temp_front].time;
        temp_front++;
    }
    printf("Remaining Time: %d\n", total);
}

void clear(void){
    while(getchar() != '\n');
}

void readline(char* buffer){
    int i = 0;
    char c;
    while(1){
        c = getc(stdin);
        if(c == '\n'){
            buffer[i] = '\0';
            return;
        }else{
            buffer[i] = c;
        }
        i++;
    }
}

int main(void){
    char buffer[1000];
    char Q[1000];
    while(1){
        scanf("%s", Q);
        if(strcmp(Q,"add") == 0){
            item new;
            clear();
            readline(buffer);
            strcpy(new.song, buffer);
            readline(buffer);
            strcpy(new.artist, buffer);
            int time;
            scanf("%d", &time);
            new.time = time;
            add(new);
        }else if(strcmp(Q,"play") == 0){
            play();
        }else{
            sum();
            break;
        }
    }
    return 0;
}
