/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }
    int x = matrixSize, y = matrixColSize[0];
    int *ans = (int *)malloc(sizeof(int) * (x * y));
    *returnSize = 0;
    int left = 0, right = y - 1, up = 0, down = x - 1;
    while (left <= right && up <= down) {
        for (int i = left; i <= right; i++) ans[(*returnSize)++] = matrix[up][i];
        for (int i = up + 1; i <= down; i++) ans[(*returnSize)++] = matrix[i][right];
        if (left < right && up < down) {
            for (int i = right - 1; i > left; i--) ans[(*returnSize)++] = matrix[down][i];
            for (int i = down; i > up; i--) ans[(*returnSize)++] = matrix[i][left];
        }
        
        left++;
        right--;
        down--;
        up++; 
    }
    return ans;
}