class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans = 0, cnt1 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                ans = min(cnt1, ans + 1);
            } else cnt1++;
        }
        return ans;
    }
};