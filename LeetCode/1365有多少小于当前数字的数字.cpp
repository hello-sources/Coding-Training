/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        int cnt = 0;
        for (int j = 0; j < numsSize; j++) {
            if (j != i && nums[j] < nums[i]) cnt++;
        }
        res[(*returnSize)++] = cnt;
    }
    return res;
}