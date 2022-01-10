/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * 100005);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i += 2) {
        for (int j = 0; j < nums[i]; j++) {
            res[(*returnSize)++] = nums[i + 1];
        }
    }
    return res;
}