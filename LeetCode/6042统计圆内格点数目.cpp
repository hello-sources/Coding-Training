class Solution {
public:
    bool check(int x, int y, vector<vector<int>> &circles) {
        for (auto & circle : circles) {
            int cx = x - circle[0];
            int cy = y - circle[1];
            int cr = circle[2];
            if (cx * cx + cy * cy <= cr * cr) return true;
        }
        return false;
    }

    int countLatticePoints(vector<vector<int>>& circles) {
        int ans = 0;
        for (int i = 0; i < 201; i++) {
            for (int j = 0; j < 201; j++) {
                if (check(i, j, circles)) ans++;
            }
        }
        return ans;
    }
};