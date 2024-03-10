#include <stdio.h>

int movecount = 0;

void move (int n, char source, char dest, char spare){
    movecount++;
    if(n==1){
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }
    else{
        move(n-1,source,spare,dest);
        // move(1,source,dest,spare);
        printf("Move disk %d from %c to %c\n", n, source, dest);
        move(n-1,spare,dest,source);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    move(n, 'A', 'C', 'B');
    printf("Total moves: %d\n", movecount);
    return 0;
}

//So, while the Tower of Hanoi problem itself doesn't inherently deal with stacks, the recursive solution to the problem utilizes a stack-like behavior due to the nature of recursion.