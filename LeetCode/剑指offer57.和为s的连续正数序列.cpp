/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int*) * target);
    *returnColumnSizes = (int *)malloc(sizeof(int) * target);
    int start = 1, end = 1, sum = 0, len = target / 2;
    *returnSize = 0;
    while (start <= len) {
        if (sum == target) {
            (*returnColumnSizes)[*returnSize] = end - start;
            res[*returnSize] = (int *)malloc(sizeof(int) * (end - start));
            for (int i = start; i < end; i++) {
                res[*returnSize][i - start] = i;
            }
            (*returnSize)++;
            sum -= start++;
        }
        if (sum < target) {
            sum += end++;
        }
        if (sum > target) {
            sum -= start++;
        }
    }
    return res;
}