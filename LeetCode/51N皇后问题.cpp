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

/***********************回溯C++***************/
class Solution {
public:
    bool judge(int row, int col, vector<string> &chessboard, int n) {
        int cnt = 0;
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') return false;
        }
        return true;
    }

    void backtracking(int n, int row, vector<string> &chessboard) {
        if (n == row) {
            ans.emplace_back(chessboard);
            return ;
        }
        for (int col = 0; col < n; col++) {
            if (!judge(row, col, chessboard, n)) continue;
            chessboard[row][col] = 'Q';
            backtracking(n, row + 1, chessboard);
            chessboard[row][col] = '.';
        }
        return ;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return ans;
    }

private :
    vector<vector<string>> ans;
};