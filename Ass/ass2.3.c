//Nitis Jadipang 66070501020

//  Symmetric Matrix

#include <stdio.h>

int main(){
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int matrix[rows][cols];
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int skew, sym;

    // printf("\n");
    // for(int i=0; i<rows; i++){
    //     for(int j=0; j<cols; j++){
    //         printf("%d ", matrix[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // for(int i=0; i<rows; i++){
    //     for(int j=0; j<cols; j++){
    //         printf("%d ", matrix[j][i]);
    //     }
    //     printf("\n");
    // }
    skew = sym = 1;
    if (rows == 1 && cols == 1) {
        printf("The matrix is symmetric\n");
        return 0;
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if (matrix[i][j] != matrix[j][i]) {
                sym = 0;
            }
            if (i != j && matrix[i][j] != -matrix[j][i]) {
                skew = 0;
            }
        }
    }

    if(skew==1){
        printf("The matrix is skew-symmetric");
    }
    else if(sym==1){
        printf("The matrix is symmetric");
    }
    else{
        printf("None");
    }
    return 0;

}