//Nitis Jadipang 66070501020

// No Bracket No Printf

#include <stdio.h>
#include <stdlib.h>


int maxmin(int *marks, int n, int *max, int *min, int *posMIN, int *posMAX){
    *max = *min = *marks;
    for(int i = 0; i < n; i++){
        if (*(marks + i) > *max) {
            *max = *(marks + i);
            *posMAX = i;
        }
        if (*(marks + i) < *min) {
            *min = *(marks + i);
            *posMIN = i;
        }
    }
    printf("%d %d\n%d %d", *max, *posMAX, *min, *posMIN);
}

int main(){
    int n;
    scanf("%d", &n);
    int ARRAYSIZE = n;
    int* marks = calloc(ARRAYSIZE, sizeof(int));
    for(int i=0; i < n; ++i){
        int member;
        scanf("%d", &member);
        *(marks+i) = member;
    }
    int max, min, posMIN, posMAX;
    maxmin(marks, n, &max, &min, &posMIN, &posMAX);

    free(marks);
}