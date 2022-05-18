class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ans = 0;
        sort(special.begin(), special.end());
        ans = max(ans, special.front() - bottom);
        for (int i = 1; i < special.size(); i++) {
            ans = max(ans, special[i] - special[i - 1] - 1);
        }
        ans = max(ans, top - special.back());
        return ans;
    }
};