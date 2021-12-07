/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int visit[50][50];
bool dfs(int i, int j, int **grid, int gridSize, int *gridColSize, int row, int col, int color) {
    if (i < 0 || j < 0 || i >= gridSize || j >= *gridColSize) return false;
    if (visit[i][j]) return true;
    if (grid[i][j] != grid[row][col]) return false;
    visit[i][j] = 1;
    bool a = dfs(i - 1, j, grid, gridSize, gridColSize, row, col, color);
    bool b = dfs(i + 1, j, grid, gridSize, gridColSize, row, col, color);
    bool c = dfs(i, j - 1, grid, gridSize, gridColSize, row, col, color);
    bool d = dfs(i, j + 1, grid, gridSize, gridColSize, row, col, color);
    if (!(a && b && c && d)) grid[i][j] = color;
    return true;
}

int** colorBorder(int** grid, int gridSize, int* gridColSize, int row, int col, int color, int* returnSize, int** returnColumnSizes){
    memset(visit, 0, sizeof(int) * 50 * 50);
    dfs(row, col, grid, gridSize, gridColSize, row, col, color);
    *returnSize = gridSize;
    *returnColumnSizes = gridColSize;
    return grid;
}