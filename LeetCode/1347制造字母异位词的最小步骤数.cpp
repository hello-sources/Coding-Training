class Solution {
public:
    int minSteps(string s, string t) {
        int cs[26] = {0}, ct[26] = {0};
        for (auto x : s) {
            cs[x - 'a']++;
        }
        for (auto x : t) {
            ct[x - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (cs[i] >= ct[i]) continue;
            ans += ct[i] - cs[i];
        }
        return ans;
    }
};