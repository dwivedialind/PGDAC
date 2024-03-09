#include<stdio.h>
#define SIZE1 2
#define SIZE2 3
#define SIZE3 2

void printMatrix(int rows, int cols, int matrix[rows][cols]);

int main(){
    
    // int matrix1[SIZE1][SIZE2] = {1,2,3,4,5,6}; //Input matrix1
    // int matrix2[SIZE2][SIZE3] = {10,11,20,21,30,31}; //Input matrix2

    int matrix1[2][3] = { {0, 1, 2}, {3, 4, 5} };
  int matrix2[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    
    int outputMatrix[SIZE1][SIZE3]; 

   for(int i = 0 ; i < SIZE1; i++){
    for(int j = 0 ; j < SIZE3; j++){
        outputMatrix[i][j] = 0;
        for(int k = 0 ; k < SIZE2; k++){
            outputMatrix[i][j] += matrix1[i][k]*matrix2[k][j];
        }
    }
   }
    printMatrix(SIZE1, SIZE3, outputMatrix);

}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}