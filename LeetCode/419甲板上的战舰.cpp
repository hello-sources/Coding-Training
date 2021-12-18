int find(int *fa, int x) {
    return fa[x] = (fa[x] == x ? x : find(fa, fa[x]));
}

void merge(int *fa, int x, int y) {
    int fx = find(fa, x), fy = find(fa, y);
    if (fx == fy) return ;
    fa[fy] = fx;
    return ;
}

int countBattleships(char** board, int boardSize, int* boardColSize){
    int m = boardSize, n = boardColSize[0];
    int fa[m * n];
    for (int i = 0; i < m * n; i++) {
        fa[i] = i;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int ind = i * n + j;
            if (board[i][j] == 'X') {
                if (i + 1 < m && board[i + 1][j] == 'X') merge(fa, i * n + j, (i + 1) * n + j);
                if (j + 1 < n && board[i][j + 1] == 'X') merge(fa, i * n + j, i * n + j + 1);
            }
        }
    } 
    int cnt = 0;
    for (int i = 0; i < m * n; i++) {
        if (fa[i] == i && board[i / n][i % n] == 'X') cnt++;
    }
    return cnt;
}