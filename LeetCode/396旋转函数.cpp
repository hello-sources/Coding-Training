class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int temp = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            temp += i * nums[i];
        }
        int ans = temp;
        for (int i = n - 1; i > 0; i--) {
            temp += sum - n * nums[i];
            ans = max(ans, temp);
        }
        return ans;
    }
};