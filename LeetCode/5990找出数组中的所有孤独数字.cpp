

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_N 1000005

int* findLonely(int* nums, int numsSize, int* returnSize){
    int *ans = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    int temp[MAX_N] = {0};
    for (int i = 0; i < numsSize; i++) {
        temp[nums[i]]++;
    }
    for (int i = 0; i < MAX_N; i++) {
        if (i == 0 && temp[0] == 1 && temp[1] == 0) ans[(*returnSize)++] = 0;
        else if (i > 0) {
            if (temp[i - 1] == 0 && temp[i] == 1 && temp[i + 1] == 0) ans[(*returnSize)++] = i;
        }
    }
    return ans;
}