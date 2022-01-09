
bool checkValid(int** matrix, int matrixSize, int* matrixColSize){
    int nums[105];
    memset(nums, 0, sizeof(int) * 105);
    for (int i = 0; i < matrixSize; i++) {
        memset(nums, 0, sizeof(int) * 105);
        for (int j = 0; j < matrixColSize[0]; j++) {
            nums[matrix[i][j]]++;
        }
        for (int i = 1; i <= matrixSize; i++) {
            if (nums[i] != 1) return false;
        }
    }
    for (int i = 0; i < matrixSize; i++) {
        memset(nums, 0, sizeof(int) * 105);
        for (int j = 0; j < matrixColSize[0]; j++) {
            nums[matrix[j][i]]++;
        }
        for (int i = 1; i <= matrixSize; i++) {
            if (nums[i] != 1) return false;
        }
    }
    return true;
}