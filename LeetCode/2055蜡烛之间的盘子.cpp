/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* platesBetweenCandles(char * s, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * queriesSize);
    memset(res, 0, sizeof(int) * queriesSize);
    int len = strlen(s);
    int *cnt = (int *)malloc(sizeof(int) * len);
    for (int i = 0, sum = 0; i < len; i++) {
        if (s[i] == '*') sum++;
        cnt[i] = sum;
    }
    int *left = (int *)malloc(sizeof(int) * len);
    memset(left, 0, sizeof(int) * len);
    for (int i = 0, ind = -1; i < len; i++) {
        if (s[i] == '|') ind = i;
        left[i] = ind;
    }
    int *right = (int *)malloc(sizeof(int) * len);
    memset(right, 0, sizeof(int) * len);
    for (int i = len - 1, ind = -1; i >= 0; i--) {
        if (s[i] == '|') ind = i;
        right[i] = ind;
    }
    for (int i = 0; i < queriesSize; i++) {
        int l = right[queries[i][0]], r = left[queries[i][1]];
        res[i] = l == -1 || r == -1 || l >= r ? 0 : cnt[r] - cnt[l];
    }
    *returnSize = queriesSize;
    free(left);
    free(right);
    free(cnt);
    return res;
}