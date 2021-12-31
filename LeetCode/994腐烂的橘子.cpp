int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int m = gridSize, n = gridColSize[0];
    int queue[m * n][2];
    int bad = 0, steps = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[bad][0] = i;
                queue[bad++][1] = j;
            }   
        }
    }
    int head = 0, tail = bad;
    while (head < tail) {
        int thead = head, ttail = tail;
        for (int i = thead; i < ttail; i++) {
            for (int j = 0; j < 4; j++) {
                int tx = queue[i][0] + dir[j][0];
                int ty = queue[i][1] + dir[j][1];
                if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
                if (grid[tx][ty] == 1) {
                    grid[tx][ty] = 2;
                    queue[bad][0] = tx;
                    queue[bad++][1] = ty;
                }
            }
        }
        head = ttail;
        tail = bad;
        steps++;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) return -1;
        }
    }
    return steps > 0 ? steps - 1 : 0;
}