class Solution {
public:
    bool judge(const string &x, const string &pattern) {
        if (x.size() != pattern.size()) return false;
        int t[256] = {0}, s[256] = {0};
        for (int i = 0; i < x.size(); i++) {
            if (t[x[i]] == 0) {
                if (s[pattern[i]]) return false;
                t[x[i]] = pattern[i];
                s[pattern[i]] = x[i];
            }
            int val = t[x[i]];
            if (val - pattern[i]) return false;
        }
        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (auto &x : words) {
            if (judge(x, pattern)) res.emplace_back(x);
        }
        return res;
    }
};