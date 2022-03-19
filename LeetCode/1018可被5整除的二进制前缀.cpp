/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize){
    bool *ans = (bool *)malloc(sizeof(bool) * numsSize);
    *returnSize = numsSize;
    int temp = 0;
    for (int i = 0; i < numsSize; i++) {
        temp = ((temp << 1) + nums[i]) % 5;
        ans[i] = temp == 0;
    }
    return ans;
}