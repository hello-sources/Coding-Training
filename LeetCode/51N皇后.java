class Solution {
    List<List<String>> ans = new ArrayList<>();
    public List<List<String>> solveNQueens(int n) {
        char[][] chs = new char[n][n];
        for (char[] c : chs) {
            Arrays.fill(c, '.');
        }
        backtracking(n, 0, chs);
        return ans;
    }

    public void backtracking(int n, int row, char[][] chs) {
        if (row == n) {
            ans.add(changeToList(chs));
            return ;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(row, i, n, chs)) {
                chs[row][i] = 'Q';
                backtracking(n, row + 1, chs);
                chs[row][i] = '.';
            }
        }
        return ;
    }

    public boolean isValid(int row, int col, int n, char[][] chs) {
        for (int i = 0; i < row; i++) {
            if (chs[i][col] == 'Q') {
                return false;
            }
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chs[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j <= n - 1; i--, j++) {
            if (chs[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    public List changeToList(char[][] chs) {
        List<String> list = new ArrayList<>();
        for (char[] c : chs) {
            list.add(String.copyValueOf(c));
        }
        return list;
    }
}