class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int max_num = n * n, cur = 1;
        int rols = 0, cols = 0;
        int dir_ind = 0;
        vector<vector<int>> ans(n, vector<int>(n));
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (cur <= max_num) {
            ans[rols][cols] = cur++;
            int next_rols = rols + dir[dir_ind][0];
            int next_cols = cols + dir[dir_ind][1];
            if (next_cols < 0 || next_cols >= n || next_rols < 0 || next_rols >= n || ans[next_rols][next_cols]) {
                dir_ind = (dir_ind + 1) % 4;
            }
            rols += dir[dir_ind][0];
            cols += dir[dir_ind][1];
        }
        return ans;
    }
};

/**********************层模拟********************/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int left = 0, right = n - 1, top = 0, down = n - 1;
        int num = 1;
        while (left <= right && top <= down) {
            for (int col = left; col <= right; col++) ans[top][col] = num++;
            for (int row = top + 1; row <= down; row++) ans[row][right] = num++;
            if (left < right && top < down) {
                for (int col = right - 1; col > left; col--) ans[down][col] = num++;
                for (int row = down; row > top; row--) ans[row][left] = num++;
            }
            left++;
            right--;
            top++;
            down--;
        }
        return ans;
    }
};