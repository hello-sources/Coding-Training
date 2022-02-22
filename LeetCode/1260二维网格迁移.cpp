/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
//     int col = *gridColSize;
//     *returnSize = gridSize;
//     *returnColumnSizes = (int *)malloc(sizeof(int) * gridSize);
//     int **ans = (int **)malloc(sizeof(int *) * gridSize);
//     k %= (gridSize * col);
//     for (int i = 0; i < gridSize; i++) {
//         (*returnColumnSizes)[i] = col;
//         ans[i] = (int *)malloc(sizeof(int) * col);
//         for (int j = 0; j < col; j++) {
//             int id = (gridSize * col + i * col + j - k) % (gridSize * col);
//             ans[i][j] = grid[id / col][id % col];
//         } 
//     }
//     return ans;
// }

void reverseCol(int** grid, int rows, int left, int right) {
    while (left < right) {
        // 对一列的元素迁移
        for (int i = 0; i < rows; i++) {
            int tmp = grid[i][left];
            grid[i][left] = grid[i][right];
            grid[i][right] = tmp;
        }
        left++, right--;
    }
}

void reverseRow(int** grid, int col, int low, int high) {
    while (low < high) {
        // 一列元素上下翻转
        int tmp = grid[low][col];
        grid[low][col] = grid[high][col];
        grid[high][col] = tmp;
        low++, high--;
    }
}

int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
    int m = gridSize, n = gridColSize[0];
    returnSize[0] = gridSize;
    returnColumnSizes[0] = gridColSize;
    // 1. 某列走过 n 列次数即为该列向下旋转次数
    for (int col = 0; col < n; col++) {
        int shift = ((col + k) / n) % m;  // (col + k) / n 经过 n 几次，上下翻转取余 m 次
        reverseRow(grid, col, 0, m - 1);
        reverseRow(grid, col, 0, shift - 1);
        reverseRow(grid, col, shift, m - 1);
    }
    // 2. 把对应列移动找到
    int move = k % n;  // 列的水平移动次数
    reverseCol(grid, m, 0, n - 1);
    reverseCol(grid, m, 0, move - 1);
    reverseCol(grid, m, move, n - 1);
    return grid;
}