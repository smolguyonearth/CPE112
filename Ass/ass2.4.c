//Nitis Jadipang 66070501020

// Matrix Multiplication

#include <stdio.h>

void createMatrix(int rows, int cols, int arr[rows][cols]){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf("%d", &arr[i][j]);
        }
    }
}

int main(){
    int rows_I, cols_I;
    scanf("%d %d", &rows_I, &cols_I);
    int matrix_I[rows_I][cols_I];
    createMatrix(rows_I, cols_I, matrix_I);
    int rows_II, cols_II;
    scanf("%d %d", &rows_II, &cols_II);
    int matrix_II[rows_II][cols_II];
    createMatrix(rows_II, cols_II, matrix_II);

    int mul[rows_II][cols_II];

    // Initialize mul matrix to zero
    for(int i = 0; i < rows_I; i++){
        for(int j = 0; j < cols_II; j++){
            mul[i][j] = 0;
        }
    }

    for(int i = 0; i < rows_I; i++){
        for(int j = 0; j < cols_II; j++){
            for(int k = 0; k < rows_II; k++){
                    mul[i][j] += matrix_I[i][k]*matrix_II[k][j];
                }
            }
        }

    if (cols_I != rows_II){
        printf("Not Compatible");
    }
    else{
        for(int i=0; i < rows_I; i++){
        for(int j=0; j < cols_II; j++){
            printf("%d " ,mul[i][j]);
        }
        printf("\n");
        }
    }
}

