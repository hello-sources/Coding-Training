/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* goodDaysToRobBank(int* security, int securitySize, int time, int* returnSize) {
    int * left = (int *)malloc(sizeof(int) * securitySize);
    int * right = (int *)malloc(sizeof(int) * securitySize);
    memset(left, 0, sizeof(int) * securitySize);
    memset(right, 0, sizeof(int) * securitySize);
    for (int i = 1; i < securitySize; i++) {
        if (security[i] <= security[i - 1]) {
            left[i] = left[i - 1] + 1;
        }
        if (security[securitySize - i - 1] <= security[securitySize - i]) {
            right[securitySize - i - 1] = right[securitySize - i] + 1;
        }
    }

    int * ans = (int *)malloc(sizeof(int) * securitySize);
    int pos = 0;
    for (int i = time; i < securitySize - time; i++) {
        if (left[i] >= time && right[i] >= time) {
            ans[pos++] = i;
        }
    }
    free(left);
    free(right);
    *returnSize = pos;
    return ans;
}