/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* longestCommonSubsequence(int** arrays, int arraysSize, int* arraysColSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * 105);
    int num[105] = {0};
    *returnSize = 0;
    for (int i = 0; i < arraysSize; i++) {
        for (int j = 0; j < arraysColSize[i]; j++) {
            num[arrays[i][j]]++;
        }
    }
    for (int i = 0; i < 105; i++) {
        if (num[i] == arraysSize) res[(*returnSize)++] = i;
    }
    return res;
}