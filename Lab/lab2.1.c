//Nitis Jadipang 66070501020

// No Bracket

#include <stdio.h>
#include <stdlib.h>

void output(int *marks, int n){
    int binary;
    scanf("%d", &binary);
    if (binary == 1){
        if(*(marks+1) == 0){
            printf("none");
        }
        for(int i=1; i < n; i+=2){
            printf("%d ", *(marks+i));
        }
    }
    else if (binary == 0){
        if(*(marks) == 0){
            printf("none");
        }
        for(int i=0; i<n; i+=2){
            printf("%d ", *(marks+i));
        }
    }
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

    // for(int i=0; i < n; ++i){
    //     printf("%d", *(marks+i));
    // }

    output(marks, n);
    free(marks);
}