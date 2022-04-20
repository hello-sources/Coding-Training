class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
        int ans = 0;
        vector<int> cmp(n + 1, 0);
        for (auto &x : lights) {
            cmp[max(0, x[0] - x[1])] += 1;
            cmp[min(n, x[0] + x[1] + 1)] -= 1;
        }
        for (int i = 1; i <= n; i++) cmp[i] += cmp[i - 1];
        for (int i = 0; i < n; i++) {
            if (cmp[i] < requirement[i]) continue;
            ans++;
        }
        return ans;
    }
};