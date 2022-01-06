bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int x[9], y[9], z[9];
    for (int i = 0; i < 9; i++) x[i] = y[i] = z[i] = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;
            int num = board[i][j] - '0';
            if (x[i] & (1 << num)) return false;
            if (y[j] & (1 << num)) return false;
            if (z[i / 3 * 3 + j / 3] & (1 << num)) return false;
            x[i] |= (1 << num);
            y[j] |= (1 << num);
            z[i / 3 * 3 + j / 3] |= (1 << num);
        }
    }
    return true;
}