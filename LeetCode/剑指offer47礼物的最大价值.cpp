int maxValue(int** grid, int gridSize, int* gridColSize){
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (i == 0 && j == 0) continue;
            if (i == 0) {
                grid[i][j] = grid[i][j] + grid[i][j - 1];
            } else if (j == 0) {
                grid[i][j] = grid[i][j] + grid[i - 1][j];
            } else {
                grid[i][j] = fmax(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }
    }
    return grid[gridSize - 1][gridColSize[0] - 1];
}