class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return nums[0];
        int left = 0, right = len - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[0] <= nums[mid] && nums[mid] > nums[len - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return nums[left];
    }
};