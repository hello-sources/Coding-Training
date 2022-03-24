/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * 2);
    memset(res, 0, sizeof(int) * 2);
    *returnSize = 2;
    int num[10005] = {0};
    for (int i = 0; i < numsSize; i++) {
        num[nums[i]]++;
        if (num[nums[i]] == 2) {
            res[0] = nums[i];
        }
    }
    for (int i = 1; i <= numsSize + 1; i++) {
        if (num[i] == 0) {
            res[1] = i;
            break;
        }
    }
    return res;
}