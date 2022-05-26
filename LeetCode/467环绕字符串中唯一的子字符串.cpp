class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26);
        int temp = 0;
        for (int i = 0; i < p.size(); i++) {
            if (i && (p[i] - p[i - 1] + 26) % 26 == 1) temp++;
            else temp = 1;
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], temp);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};