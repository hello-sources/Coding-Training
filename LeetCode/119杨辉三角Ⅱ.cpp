/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * (rowIndex + 1));
    memset(res, 0, sizeof(int) * (rowIndex + 1));
    int *cur = (int *)malloc(sizeof(int) * (rowIndex + 1));
    memset(cur, 0, sizeof(int) * (rowIndex + 1));
    for (int i = 0; i <= rowIndex; i++) {
        cur[0] = cur[i] = 1;
        for (int j = 1; j < i; j++) {
            cur[j] = res[j - 1] + res[j];
        }
        int *temp = res;
        res = cur;
        cur = temp;
    }
    *returnSize = rowIndex + 1;
    return res;
}