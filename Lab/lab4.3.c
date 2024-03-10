//Nitis Jadipang 66070501020

// Tower of Hanoi

#include <stdio.h>

int moveCount = 0;

void towerOfHanoi(int disks, char source, char destination, char auxiliary) {
    moveCount++;
    if (disks == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(disks - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", disks, source, destination);
    towerOfHanoi(disks - 1, auxiliary, destination, source);
}

int main(void) {
    int numDisks;
    // printf("Enter the number of disks: ");
    scanf("%d", &numDisks);
    towerOfHanoi(numDisks, 'A', 'C', 'B');
    printf("Total moves: %d\n", moveCount);
    return 0;
}