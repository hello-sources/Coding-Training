int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize){
    int top[55] = {0};
    int left[55] = {0};
    int total = 0;
    for (int i = 0; i < gridSize; i++) {
        int max = 0;
        for (int j = 0; j < gridColSize[0]; j++) {
            max = fmax(grid[i][j], max);
        }
        top[i] = max;
    }
    for (int i = 0; i < gridColSize[0]; i++) {
        int max = 0;
        for (int j = 0; j < gridSize; j++) {
            max = fmax(max, grid[j][i]);
        }
        left[i] = max;
    }
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            total += fmin(left[i], top[j]) - grid[i][j];
        }
    }
    return total;
}