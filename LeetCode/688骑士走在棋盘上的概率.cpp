int dir[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

double knightProbability(int n, int k, int row, int column){
    double dp[200][30][30];
    memset(dp, 0, sizeof(dp));
    for (int step = 0; step <= k; step++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (step == 0) dp[step][i][j] = 1.0;
                else {
                    for (int k = 0; k < 8; k++) {
                        int x = i + dir[k][0], y = j + dir[k][1];
                        if (x >= 0 && x < n && y >= 0 && y < n) {
                            dp[step][i][j] += dp[step - 1][x][y] / 8;
                        }
                    }
                }
            }
        }
    }
    return dp[k][row][column];
}