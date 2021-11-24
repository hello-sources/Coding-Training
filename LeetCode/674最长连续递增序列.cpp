//贪心，主要就是固定一个开始位置，然后从开始位置进行遍历，计算得到最大的长度，并且不断更新
int findLengthOfLCIS(int* nums, int numsSize){
    if (numsSize == 1) return 1;
    int ans = 0, l = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i - 1] >= nums[i]) {
            l = i;
        }
        ans = fmax(ans, i - l + 1);
    }
    return ans;
}