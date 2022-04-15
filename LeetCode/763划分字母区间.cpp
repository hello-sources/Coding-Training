class Solution {
public:
    vector<int> partitionLabels(string s) {
        int ch[26];
        for (int i = 0; i < s.size(); i++) {
            ch[s[i] - 'a'] = i;
        }
        vector<int> ans;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, ch[s[i] - 'a']);
            if (i == end) {
                ans.emplace_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
};