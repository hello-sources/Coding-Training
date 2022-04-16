class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while (nums.size() > 1) {
            vector<int> vec;
            for (int i = 1; i < nums.size(); i++) vec.emplace_back((nums[i - 1] + nums[i]) % 10);
            // copy(vec.begin(), vec.end(), nums.begin());
            nums = move(vec);
        }
        return nums[0];
    }
};