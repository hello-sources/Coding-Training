int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int ans = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j]) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int tx = i + dx[k];
                    int ty = j + dy[k];
                    if (tx < 0 || tx >= gridSize || ty < 0 || ty >= gridColSize[0] || !grid[tx][ty]) cnt++;
                }
                ans += cnt;
            }
        }
    }
    return ans;
}