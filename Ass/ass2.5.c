//Nitis Jadipang 66070501020

// Spiral Array Printer

#include <stdio.h>
#include <stdio.h>

int main(){
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int matrix[rows][cols];
    for(int i=0; i< rows; i++){
        for(int j=0; j < cols; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    int sr =0, sl = 0;

    while (sr < rows && sl < cols){

        for (int i = sl; i < cols; ++i){
            printf("%d ", matrix [sr][i]);
        }
        sr++;
        
        for (int i = sr; i < rows; ++i){
            printf("%d ", matrix [i][cols-1]);
        }
        cols--;
        
        if (sr < rows){
            for (int i = cols-1; i >= sl; --i){
                printf("%d ", matrix[rows-1][i]);
            }
            rows--;
        }

        if(sl < cols) {
            for (int i = rows -1; i >= sr; --i){
                printf("%d ", matrix[i][sl]);
            }
            sl++;
        }
    }
}