/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getModifiedArray(int length, int** updates, int updatesSize, int* updatesColSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * length);
    memset(res, 0, sizeof(int) * length);
    for (int i = 0; i < updatesSize; i++) {
        for (int j = updates[i][0]; j <= updates[i][1]; j++) {
            res[j] += updates[i][2];
        }
    }
    *returnSize = length;
    return res;
}