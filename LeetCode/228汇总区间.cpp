/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** summaryRanges(int* nums, int numsSize, int* returnSize){
    char **res = (char **)malloc(sizeof(char *) * numsSize);
    *returnSize = 0;
    int i = 0;
    while (i < numsSize) {
        int start = i++;
        while (i < numsSize && nums[i - 1] + 1 == nums[i]) i++;
        int end = i - 1;
        char *temp = (char *)malloc(sizeof(char) * 25);
        sprintf(temp, "%d", nums[start]);
        if (start < end) {
            sprintf(temp + strlen(temp), "->%d", nums[end]);
        }
        res[(*returnSize)++] = temp;
    }
    return res;
}