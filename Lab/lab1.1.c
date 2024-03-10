//Nitis Jadipang 66070501020

//Sets

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int set[n];
    int setSize = 0;

    set[0] = arr[0];
    setSize++;

    for (int i = 1; i < n; i++) {
        int exists = 0;
        for (int j = 0; j < setSize; j++) {
            if (arr[i] == set[j]) {
                exists = 1;
                break;
            }
        }

        if (!exists) {
            set[setSize] = arr[i];
            setSize++;
        }
    }

    printf("%d", setSize);
    printf("\n");
    for (int i = 0; i < setSize; i++) {
        printf("%d ", set[i]);
        // if(i != setSize-1)
        //     printf(" ");
    }

    return 0;
}