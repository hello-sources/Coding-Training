/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    int *ans = (int *)malloc(sizeof(int) * numsSize);
    int tail = -1;
    for (int i = 0; i < indexSize; i++) {
        ++tail;
        for (int j = tail; j > index[i]; j--) {
            ans[j] = ans[j - 1];
        }
        ans[index[i]] = nums[i];
    }
    *returnSize = numsSize;
    return ans;
}