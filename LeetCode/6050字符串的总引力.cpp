class Solution {
public:
    long long appealSum(string s) {
        int len = s.size();
        long long ans = 0;
        vector<int> ch(26);
        for (int i = 0; i < 26; i++) ch[i] = len;
        for (int i = len - 1; i >= 0; i--) {
            ch[s[i] - 'a'] = i;
            for (int j = 0; j < 26; j++) {
                if (ch[j] < len) ans += len - ch[j];
            }
        }   
        return ans;
    }
};