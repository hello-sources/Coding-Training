class Solution {
public:
    int get_manhadun(vector<int> &a, vector<int> &b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        vector<int> start(2);
        int len = get_manhadun(start, target);
        for (auto ghost : ghosts) {
            int temp_len = get_manhadun(ghost, target);
            if (temp_len <= len) return false;
        }
        return true;
    }
};