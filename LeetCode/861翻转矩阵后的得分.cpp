int matrixScore(int** grid, int gridSize, int* gridColSize){
    int ans = 0;
    for (int i = 0; i < gridSize; i++) {
        int flag = grid[i][0];
        for (int j = 0; j < gridColSize[0]; j++) {
            if (flag) break;
            if (grid[i][j] == 0) grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }
    for (int i = 1; i < gridColSize[0]; i++) {
        int cnt0 = 0, cnt1 = 0;
        for (int j = 0; j < gridSize; j++) {
            if (grid[j][i] == 0) cnt0++;
            else cnt1++;
        }
        if (cnt0 > cnt1) {
            for (int j = 0; j < gridSize; j++) {
                if (grid[j][i] == 0) grid[j][i] = 1;
                else grid[j][i] = 0;
            }
        }
    }
    for (int i = 0; i < gridSize; i++) {
        int temp = 0;
        for (int j = 0; j < gridColSize[0]; j++) {
            temp += grid[i][j];
            if (j < gridColSize[0] - 1) temp <<= 1;
        }
        ans += temp;
    }
    return ans;
}