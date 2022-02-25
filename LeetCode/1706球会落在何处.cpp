/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findBall(int** grid, int gridSize, int* gridColSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * gridColSize[0]);
    *returnSize = gridColSize[0];
    memset(res, -1, sizeof(int) * gridColSize[0]);
    for (int i = 0; i < gridColSize[0]; i++) {
        int col= i;
        for (int j = 0; j < gridSize; j++) {
            int dir = grid[j][col];
            col += dir;
            if (col < 0 || col == gridColSize[0] || grid[j][col] != dir) {
                col = -1;
                break;
            }
        }
        if (col >= 0) {
            res[i] = col;
        }
    }
    return res;
}