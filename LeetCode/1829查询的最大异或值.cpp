/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int find(int x, int maximumBit) {
    return x ^= ((1 << maximumBit) - 1);
}

int* getMaximumXor(int* nums, int numsSize, int maximumBit, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * (numsSize + 5));
    int sum = 0;
    for (int i = 0; i < numsSize; i++) sum ^= nums[i];
    for (int i = 0; i < numsSize; i++) {
        res[i] = find(sum, maximumBit);
        sum ^= nums[numsSize - i - 1];
    }
    *returnSize = numsSize;
    return res;
}