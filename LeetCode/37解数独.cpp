class Solution {
public:
    bool judge(int row, int col, char ch, vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch) return false;
        }
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == ch) return false;
        }
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;
        for (int i = srow; i < srow + 3; i++) {
            for (int j = scol; j < scol + 3; j++) {
                if (board[i][j] == ch) return false;
            }
        }
        return true;
    }

    bool backtracking(vector<vector<char>> &board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') continue;
                for (char ch = '1'; ch <= '9'; ch++) {
                    if (!judge(i, j, ch, board)) continue;
                    board[i][j] = ch;
                    if (backtracking(board)) return true;
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
        return ;
    }
};