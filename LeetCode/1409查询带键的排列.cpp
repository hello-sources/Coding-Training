/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void calc(int *num, int ind, int len) {
    int temp = num[ind];
    for (int i = ind - 1; i >= 0; i--) {
        num[i + 1] = num[i];
    }
    num[0] = temp;
}

int* processQueries(int* queries, int queriesSize, int m, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * queriesSize);
    int num[m + 1];
    *returnSize = 0;
    for (int i = 0; i <= m; i++) {
        num[i] = i + 1;
    }
    for (int i = 0; i < queriesSize; i++) {
        for (int j = 0; j < m; j++) {
            if (queries[i] == num[j]) {
                res[(*returnSize)++] = j;
                calc(num, j, m);
            }
        }
    }
    return res;
}