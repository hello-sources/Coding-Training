/**
 * 
 * @param matrix int整型二维数组 
 * @param matrixRowLen int matrix数组行数
 * @param matrixColLen int* matrix数组列数
 * @return int整型一维数组
 * @return int* returnSize 返回数组行数
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */
int* spiralOrder(int** matrix, int matrixRowLen, int* matrixColLen, int* returnSize ) {
    // write code here
    if (matrixRowLen == 0 || matrixColLen[0] == 0) {
        *returnSize = 0;
        return NULL;
    }
    int m = matrixRowLen, n = matrixColLen[0];
    int *ans = (int *)malloc(sizeof(int) * (m * n));
    int left = 0, right = n - 1, up = 0, down = m - 1;
    *returnSize = 0;
    while (left <= right && up <= down) {
        for (int i = left; i <= right; i++) {
            ans[(*returnSize)++] = matrix[up][i];
        }
        for (int i = up + 1; i <= down; i++) {
            ans[(*returnSize)++] = matrix[i][right];
        }
        if (left < right && up < down) {
            for (int i = right - 1; i > left; i--) {
                ans[(*returnSize)++] = matrix[down][i];
            }
            for (int i = down; i > up; i--) {
                ans[(*returnSize)++] = matrix[i][left];
            }
        }
        left++;
        right--;
        up++;
        down--;
    }
    return ans;
}