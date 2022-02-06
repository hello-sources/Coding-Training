void dfs(int **grid, int m, int n, int i, int j, int *max, int sum) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return ;
    int temp = grid[i][j];
    sum += temp;
    *max = fmax(*max, sum);
    grid[i][j] = 0;
    dfs(grid, m, n, i - 1, j, max, sum);
    dfs(grid, m, n, i + 1, j, max, sum);
    dfs(grid, m, n, i, j - 1, max, sum);
    dfs(grid, m, n, i, j + 1, max, sum);
    grid[i][j] = temp;
    return ;
}

int getMaximumGold(int** grid, int gridSize, int* gridColSize){
    int res = 0, max;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == 0) continue;
            max = 0;
            dfs(grid, gridSize, gridColSize[0], i, j, &max, 0);
            res = fmax(res, max);
        }
    }
    return res;
}