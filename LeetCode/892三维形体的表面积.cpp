int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int ans = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            for (int k = 0; k < grid[i][j]; k++) {
                ans += 6;
                if (k > 0) ans -= 2;
                if (i > 0 && grid[i - 1][j] > k) ans -= 2;
                if (j > 0 && grid[i][j - 1] > k) ans -= 2;
            }
        }
    }
    return ans;
}