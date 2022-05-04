class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int even_sum = 0;
        for (auto &x : nums) {
            if (x % 2 == 0) even_sum += x;
        }
        for (int i = 0; i < queries.size(); i++) {
            int val = queries[i][0];
            int ind = queries[i][1];
            if (nums[ind] % 2 == 0) even_sum -= nums[ind];
            nums[ind] += val;
            if (nums[ind] % 2 == 0) even_sum += nums[ind];
            ans.emplace_back(even_sum);
        }
        return ans;
    }
};