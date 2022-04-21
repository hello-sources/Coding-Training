class Solution {
public:
    long long maximumSumScore(vector<int>& nums) {
        vector<long long> ans(nums.size() + 1, 0);
        vector<long long> res(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            ans[i + 1] = nums[i] + ans[i];
        }
        long long temp = ans[nums.size() + 1];
        for (int i = 1; i < nums.size() + 1; i++) {
            res[i] = max(temp - ans[i], ans[i]);
        }
        return *max_element(res.begin(), res.end());
    }
};