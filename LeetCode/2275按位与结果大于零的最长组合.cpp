class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int max_len = 0;
        for (int i = 0; i < 32; i++) {
            int len = 0;
            for (int j = 0; j < candidates.size(); j++) {
                if ((1 << i) & candidates[j]) len++;
            }
            max_len = max(max_len, len);
        }
        return max_len;
    }
};