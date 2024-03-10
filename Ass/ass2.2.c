//Nitis Jadipang 66070501020

// Jump game

#include <stdio.h>

int minJumps(int arr[], int start, int end) {
    if (start == end) {
        return 0;
    }

    if (arr[start] == 0) {
        return -1;
    }

    int minSteps = -1;

    for (int i = 1; i <= arr[start] && start + i <= end; i++) {
        int jumps = minJumps(arr, start + i, end);
        if (jumps != -1 && (minSteps == -1 || jumps + 1 < minSteps)) {
            minSteps = jumps + 1;
        }
    }
    return minSteps;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int steps = minJumps(arr, 0, n - 1);

    if (steps == -1) {
        printf("Not Possible\n");
    } else {
        printf("%d\n", steps);
    }

    return 0;
}
