class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size(), ans = 0;
        for (int i = 0; i < 2 * len - 1; i++) {
            int l = i / 2, r = i / 2 + i % 2;
            while (l >= 0 && r < len && s[l] == s[r]) {
                l--;
                r++;
                ans++;
            }
        }
        return ans;
    }
};