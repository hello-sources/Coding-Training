/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** groupThePeople(int* groupSizes, int groupSizesSize, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *) * groupSizesSize);
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * groupSizesSize);
    int hash[500], group;
    memset(hash, 0xcf, sizeof(hash));
    for (int i = 0; i < groupSizesSize; i++) {
        group = groupSizes[i];
        if (hash[group] < 0 || (hash[group] & 1023) == group) {
            res[*returnSize] = (int *)malloc(sizeof(int) * group);
            hash[group] = *returnSize<<10;
            returnColumnSizes[0][(*returnSize)++] = group;
        }
        res[hash[group] >> 10][hash[group] & 1023] = i;
        hash[group]++;
    }
    return res;
}