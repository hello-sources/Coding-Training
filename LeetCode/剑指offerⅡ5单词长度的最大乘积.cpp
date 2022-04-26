class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        int ans = 0;
        vector<int> mask(len);
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                mask[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if ((mask[i] & mask[j]) == 0) {
                    ans = max(ans, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};