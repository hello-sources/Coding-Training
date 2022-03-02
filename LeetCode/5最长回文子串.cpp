class Solution {
public:
    string get_new_str(string &s) {
        string new_s = "#";
        for (int i = 0; i < s.size(); i++) {
            new_s += s[i];
            new_s += "#";
        }
        return new_s;
    }
    string longestPalindrome(string s) {
        int r[2010];
        string new_s = get_new_str(s);
        int ans = 0, ind = 0;
        for (int i = 0, j = 0, p = 0; new_s[i]; i++) {
            r[i] = 1;
            if (i <= p && i + r[2 * j - i] - 1 < p) {
                r[i] = r[2 * j - i];
            } else {
                r[i] = max(1, p - i + 1);
                while (i >= r[i] && i + r[i] < new_s.size() && new_s[i + r[i]] == new_s[i - r[i]]) {
                    r[i]++;
                }
            }
            if (i + r[i] - 1 > p) {
                j = i, p = i + r[i] - 1;
            }
            if (r[i] > ans) {
                ans = r[i], ind = i;
            }
        }
        string sub_str = new_s.substr(ind - ans + 1, 2 * ans - 1);
        string ret = "";
        for (int i = 1; i < sub_str.size(); i += 2) ret += sub_str[i];
        return ret;
    }
};