class Solution {
public:
    int cross(vector<int> &p, vector<int> &q, vector<int> &r) {
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int size = trees.size();
        if (size < 4) return trees;
        int leftMost = 0;
        for (int i = 0; i < size; i++) {
            if (trees[i][0] < trees[leftMost][0]) leftMost = i;
        }
        vector<vector<int>> ans;
        vector<bool> vis(size, false);
        int p = leftMost;
        do {
            int q = (p + 1) % size;
            for (int r = 0; r < size; r++) {
                if (cross(trees[p], trees[q], trees[r]) < 0) q = r;
            }
            for (int i = 0; i < size; i++) {
                if (vis[i] || i == p || i == q) continue;
                if (cross(trees[p], trees[q], trees[i]) == 0) {
                    ans.emplace_back(trees[i]);
                    vis[i] = true;
                }
            }
            if (!vis[q]) {
                ans.emplace_back(trees[q]);
                vis[q] = true;
            }
            p = q;
        } while (p != leftMost);
        return ans;
    }
};