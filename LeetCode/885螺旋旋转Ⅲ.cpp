class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = rStart, y = cStart, num = 1, dir = 0;
        int left = cStart - 1, right = cStart + 1, up = rStart - 1, down = rStart + 1;
        while (num <= rows * cols) {
            if (x < rows && x >= 0 && y < cols && y >= 0) {
                ans.push_back({x, y});
                num++;
            }
            if (dir == 0 && y == right) {
                dir++;
                right++;
            } else if (dir == 1 && x == down) {
                dir++;
                down++;
            } else if (dir == 2 && y == left) {
                dir++;
                left--;
            } else if (dir == 3 && x == up) {
                dir = 0;
                up--;
            }
            x += dirs[dir].first;
            y += dirs[dir].second;
        }
        return ans;
    }
};