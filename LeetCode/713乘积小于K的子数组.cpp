class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt = 0, len = nums.size();
        int temp = 1, i = 0;
        for (int j = 0; j < len; j++) {
            temp *= nums[j];
            while (i <= j && temp >= k) {
                temp /= nums[i];
                i++;
            }
            cnt += j - i + 1;
        }
        return cnt;
    }
};