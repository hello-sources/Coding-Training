int projectionArea(int** grid, int gridSize, int* gridColSize){
    int ans = 0;
    for (int i = 0; i < gridSize; i++) {
        int max = INT_MIN;
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j]) ans++;
            max = fmax(max, grid[i][j]);
        }
        ans += max;
    }
    for (int i = 0; i < gridColSize[0]; i++) {
        int max = INT_MIN;
        for (int j = 0; j < gridSize; j++) {
            max = fmax(max, grid[j][i]);
        }
        ans += max;
    }
    return ans;
}