typedef struct {
    int **matrix;
    int size;
} NumMatrix;


NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    NumMatrix *obj = (NumMatrix *)malloc(sizeof(NumMatrix));
    obj->matrix = (int **)malloc(sizeof(int *) * matrixSize);
    obj->size = matrixSize;
    for (int i = 0; i < matrixSize; i++) {
        obj->matrix[i] = (int *)malloc(sizeof(int) * (matrixColSize[0] + 5));
        obj->matrix[i][0] = 0;
        for (int j = 0; j < matrixColSize[0]; j++) {
            obj->matrix[i][j + 1] = obj->matrix[i][j] + matrix[i][j];
        }
    }
    return obj;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    int ans = 0;
    for (int i = row1; i <= row2; i++) {
        ans += obj->matrix[i][col2 + 1] - obj->matrix[i][col1];
    }
    return ans;
}

void numMatrixFree(NumMatrix* obj) {
    for (int i = 0; i < obj->size; i++) {
        free(obj->matrix[i]);
    }
    free(obj);
    return ;
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 
 * numMatrixFree(obj);
*/