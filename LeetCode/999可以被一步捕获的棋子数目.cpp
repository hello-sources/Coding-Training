int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int cnt = 0;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[0]; j++) {
            if (board[i][j] == 'R') {
                for (int k = 0; k < 4; k++) {
                    int x = i, y = j;
                    while (1) {
                        x += dx[k];
                        y += dy[k];
                        if (x < 0 || x >= boardSize || y < 0 || y >= boardColSize[0] || board[x][y] == 'B') break;
                        if (board[x][y] == 'p') {
                            cnt++;
                            break;
                        }
                    }
                }
            }
        }
    }
    return cnt;
}