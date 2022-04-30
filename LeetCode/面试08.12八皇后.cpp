class Solution {
public:
    bool judge(int row, int col, vector<string> &chess, int n) {
        for (int i = 0; i < col; i++) {
            if (chess[row][col] == 'Q') return false;
        }
        for (int i = 0; i < row; i++) {
            if (chess[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chess[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chess[i][j] == 'Q') return false;
        }
        return true;
    }

    void backtracking(int row, int n, vector<string> &chess) {
        if (row == n) {
            ans.emplace_back(chess);
            return ;
        }
        for (int col = 0; col < n; col++) {
            if (!judge(row, col, chess, n)) continue;
            chess[row][col] = 'Q';
            backtracking(row + 1, n, chess);
            chess[row][col] = '.';
        }
        return ;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> chess(n, string(n, '.'));
        backtracking(0, n, chess);
        return ans;
    }

private :
    vector<vector<string>> ans;
    vector<string> temp;
};