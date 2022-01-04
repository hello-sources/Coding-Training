bool dfs(char **board, int m, int n, int i, int j, int index, char *word) {
    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[index]) return false;
    if (index + 1 == strlen(word)) return true;
    board[i][j] = '\0';
    bool res = dfs(board, m, n, i - 1, j, index + 1, word) ||
        dfs(board, m, n, i + 1, j, index + 1, word) ||
        dfs(board, m, n, i, j - 1, index + 1, word) ||
        dfs(board, m, n, i, j + 1, index + 1, word);
    board[i][j] = word[index];
    return res;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
    int m = boardSize, n = boardColSize[0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dfs(board, m, n, i, j, 0, word)) return true;
        }
    }
    return false;
}