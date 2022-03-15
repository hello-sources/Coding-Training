/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
bool judge(int *visit, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (col == visit[i] || (row + col) == (i + visit[i]) || (row - col) == (i - visit[i])) 
            return false;
    }
    return true;
}

void dfs(int row, int n, int *visit, char ***res, int *returnSize) {
    if (row == n) {
        res[*returnSize] = (char **)malloc(sizeof(char *) * n);
        for (int i = 0; i < n; i++) {
            res[*returnSize][i] = (char *)calloc(n + 1, sizeof(char));
            //res[*returnSize][i] = (char *)malloc((n + 1) * sizeof(char));
            memset(res[*returnSize][i], '.', n);
            res[*returnSize][i][visit[i]] = 'Q';
        }
        (*returnSize)++;
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (!judge(visit, row, i)) continue;
        visit[row] = i;
        dfs(row + 1, n, visit, res, returnSize);
    }
    return ;
}

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int *visit = (int *)malloc(sizeof(int) * (n + 5));
    char ***res = (char ***)malloc(sizeof(char **) * (n + 5) * (n + 5) * (n + 5));
    dfs(0, n, visit, res, returnSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = n;
    }
    return res;
}