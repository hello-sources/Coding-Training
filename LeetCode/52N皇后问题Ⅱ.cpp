bool judge(int *visit, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (col == visit[i] || (row + col) == (i + visit[i]) || (row - col) == (i - visit[i])) 
            return false;
    }
    return true;
}

void dfs(int row, int n, int *visit, int *ans) {
    if (row == n) {
        (*ans)++;
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (!judge(visit, row, i)) continue;
        else visit[row] = i;
        dfs(row + 1, n, visit, ans);
    }
    return ;
}

int totalNQueens(int n){
    int ans = 0;
    int *visit = (int *)malloc(sizeof(int) * n);
    dfs(0, n, visit, &ans);
    return ans;
}