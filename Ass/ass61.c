#include <stdio.h>

int sum(int node, int n, int *tree){
    if (node >= n){
        return 0;
    }
    return sum(node*2 + 1,n,tree) + sum(node*2 + 2,n,tree) + tree[node];
}

int check(int *tree, int n, int node){
    if(node >= n || (node*2+1 >= n && node*2+2 >= n)){
        return 1;   
    }
    int lsum = sum(node*2 + 1, n, tree);
    int rsum = sum(node*2 + 2, n, tree);
    if((tree[node] == lsum+rsum) && check(tree, n,node*2+1) && check(tree, n,node*2+2)){
        return 1;
    }
    return 0;
}

int main() {
    int tree[100];
    int n = 0; // Initialize n to 0
    while (1) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp != -1001) {
            tree[n] = tmp;
            n++;
        } else {
            break;
        }
    }
    printf(check(tree, n, 0) ? "True":"False");
    return 0; // Added return statement
}