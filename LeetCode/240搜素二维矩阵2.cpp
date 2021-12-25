bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int i = 0, j = matrixColSize[0] - 1;
    while (i < matrixSize && j >= 0) {
        if (matrix[i][j] == target) return true;
        else if (matrix[i][j] < target) i++;
        else j--;
    }
    return false;
}