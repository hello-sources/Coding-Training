/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 左右乘积列表，首先通过for循环计算得到当前位置左边的数据的乘积
 * 再从后向前遍历，计算得到当前节点右边数据的乘积
 **/

int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int sum = 1;
    int *ans = (int *)malloc(sizeof(int) * (numsSize + 5));
    for (int i = 0; i < numsSize; i++) {
        ans[i] = sum; 
        sum *= nums[i];
    }
    sum = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        ans[i] *= sum;
        sum *= nums[i];
    }
    *returnSize = numsSize;
    return ans;
}