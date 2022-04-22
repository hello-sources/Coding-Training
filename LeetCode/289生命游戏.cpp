class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dir[3] = {-1, 0, 1};
        int rows = board.size(), cols = board[0].size();
        vector<vector<int>> temp(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                temp[i][j] = board[i][j];
            }
        }
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int cnt = 0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (!(dir[i] == 0 && dir[j] == 0)) {
                            int r = row + dir[i];
                            int c = col + dir[j];
                            if ((r < rows && r >= 0) && (c < cols && c >= 0) && temp[r][c] == 1) cnt++;
                        }
                    }
                }
                if (temp[row][col] == 1 && (cnt < 2 || cnt > 3)) board[row][col] = 0;   
                if (temp[row][col] == 0 && cnt == 3) board[row][col] = 1; 
            }
        }
        return ;
    }
};