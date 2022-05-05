class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans = 0;
        for (auto &word : words) {
            int len = word.size();
            if (len > s.size()) continue;
            string temp = s.substr(0, len);
            if (temp == word) ans++;
        }
        return ans;
    }
};