class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle.size() / triangle[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; j++) {
                dp[i][j] = fmin(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            }
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        }
        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};