class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (int i = 0; i < operations.size(); i++) {
            int num = gem[operations[i][0]] / 2;
            gem[operations[i][0]] -= num;
            gem[operations[i][1]] += num;
        }
        int ans_min = *min_element(gem.begin(), gem.end());
        int ans_max = *max_element(gem.begin(), gem.end());
        return ans_max - ans_min;
    }
};