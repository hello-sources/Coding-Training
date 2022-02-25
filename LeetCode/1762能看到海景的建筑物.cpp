/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findBuildings(int* heights, int heightsSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * heightsSize);
    int max[heightsSize];
    memset(max, 0, sizeof(int) * heightsSize);
    *returnSize = 0;
    int temp_max = heights[heightsSize - 1];
    for (int i  = heightsSize - 1; i >= 0; i--) {
        max[i] = fmax(heights[i], temp_max);
        temp_max = max[i];
    }
    for (int i = 0; i < heightsSize - 1; i++) {
        if (heights[i] > max[i + 1]) res[(*returnSize)++] = i;
    }
    res[(*returnSize)++] = heightsSize - 1;
    return res;
}