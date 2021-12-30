/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * (numsSize << 1));
    *returnSize = numsSize << 1;
    for (int i = 0; i < numsSize * 2; i++) {
        res[i] = nums[i % numsSize];
    }
    return res;
}