#include<stdio.h>
int matrixColSize;
int col;
int matrixSize;

void Transpose(int** matrix, int matrixSize, int* matrixColSize, int row, int col){
    int temp1 = matrix[row][col]; //matrix[row][col]
    int temp2 = (matrix + col * matrixSize + row); //matrix[col][row]
    printf("%d   ", temp1);
    printf("%d ", temp2);
    //*(matrix + row * matrixSize + col) = temp2;
    //*(matrix + col * matrixSize + row) = temp1;
}

void ReverseRow(int** matrix, int matrixSize, int* matrixColSize, int row){
    for(int i = 0; i < *matrixColSize / 2; i++){
        int temp1 = (matrix + row * *matrixColSize + i);
        int temp2 = (matrix + row * *matrixColSize + *matrixColSize - i - 1);
        *(matrix + row * *matrixColSize + i) = temp2;
        *(matrix + row * *matrixColSize + *matrixColSize - i - 1) = temp1;
    }

}

void rotate(int* matrix, int matrixSize, int* matrixColSize){

    // Making Transpose Matrix
    for(int col=0; col< *matrixColSize; col++){
        for(int row=col; row< matrixSize; row++){                       //1   0
            int temp1 = *(matrix + row * *matrixColSize + col); //matrix[row][col]
            int temp2 = *(matrix + col * *matrixColSize + row); //matrix[col][row]
            printf("%d %d", temp1, temp2);                             //0   1
            *(matrix + row * *matrixColSize + col) = temp2;
            *(matrix + col * *matrixColSize + row) = temp1;
        }
    }
    for(int i=0; i < matrixSize; i++){
        for(int j=0; j< *matrixColSize; j++){
            //printf("%d ", *matrix[i][j]);
        }
        printf("\n");
    }

    // Make Reverse of Transpose of each row
    for (int row=0; row < matrixSize; row ++){
        //ReverseRow(matrix, matrixSize, matrixColSize, row);
    }
}
int main(){
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int col = 3;
    int *matrix_cpy[3][3];
    // for(int i=0; i< 3; i++){
    //     for(int j=0; j<3; j++){
    //         int* temp = &matrix[i][j];
    //         matrix_cpy[i][j] = temp;
    //     }
    // }
    rotate(matrix, 3, &col);
    for(int i=0; i< 3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}


