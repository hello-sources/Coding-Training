class Solution {
public:
    int check(string &s, int l) {
        unordered_map<char, int> m;
        int cnt = 0;
        for (int i = 0; s[i]; i++) {
            m[s[i]] += 1;
            if (m[s[i]] == 1) cnt += 1;
            if (i >= l) {
                m[s[i - l]] -= 1;
                if (m[s[i - l]] == 0) cnt -= 1;
            }
            if (cnt == l) return 1;
        }
        return 0;
    }
    
    int lengthOfLongestSubstring(string s) {
        int head = 0, tail = s.length(), mid;
        while (head < tail) {
            mid = (head + tail + 1) >> 1;
            if (check(s, mid)) head = mid;
            else tail = mid - 1;
        }
        return head;
    }
};