void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int mat[matrixSize][matrixSize];
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            mat[i][j] = matrix[i][j];
        }
    }
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            matrix[j][matrixSize - i - 1] = mat[i][j];
        }
    }
    return matrix;
}

// void swap(int *a, int *b) {
//     int t = *a; 
//     *a = *b;
//     *b = t;
//     return ;
// }
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; \
    b = __temp;\
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    for (int i = 0; i < matrixSize / 2; i++) {
        for (int j = 0; j < matrixSize; j++) {
            swap(matrix[i][j], matrix[matrixSize - i - 1][j]);
        }
    }
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    return ;
}