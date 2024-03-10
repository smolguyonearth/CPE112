//Nitis Jadipang 66070501020

// Sum of Diagonal Matrix

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int rows, cols, primary = 0, secondary = 0;
	scanf("%d %d", &rows, &cols);
	int **matrix = (int **)malloc(rows * sizeof(int *));
	for (int i = 0; i < rows; i++) {
		matrix[i] = (int *)malloc(cols * sizeof(int));
	}
	for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
	 for (int i = 0; i < rows && i < cols; i++) {
		 primary += matrix[i][i];
	 }
	 for (int i = 0; i < rows && i < cols; i++) {
		 secondary += matrix[i][cols - i - 1];
	 }
     if(rows != cols){
        printf("ERROR");
     }
     else{
        printf("Primary: %d\n", primary);
        printf("Secondary: %d\n", secondary);
     }
	free(matrix);
    return 0;
}

// Output
// The program calculates the sum of the elements along the primary diagonal and the secondary diagonal.

//ผลบวกเเนวทเเยง