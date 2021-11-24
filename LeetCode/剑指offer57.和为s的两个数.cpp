//双指针
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *ans = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    int head = 0, tail = numsSize - 1;
    while (head < tail) {
        if (nums[head] + nums[tail] == target) {
            ans[0] = nums[head];
            ans[1] = nums[tail];
            return ans;
        } else if (nums[head] + nums[tail] < target) {
            head++;
        } else {
            tail--;
        }
    }
    return NULL;
}