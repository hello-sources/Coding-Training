/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exchange(int* nums, int numsSize, int* returnSize){
    int low = 0, high = numsSize - 1, temp;
    while (low < high) {
        if (nums[low] % 2 == 0 && nums[high] % 2 == 1) {
            temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;
        }
        if (nums[low] % 2) low++;
        if (nums[high] % 2 == 0) high--;
    }
    *returnSize = numsSize;
    return nums;
}

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            if (nums[low] % 2 == 0 && nums[high] % 2 == 1) swap(nums[low], nums[high]);
            if (nums[low] % 2) low++;
            if (nums[high] % 2 == 0) high--;
        }
        return nums;
    }
};