/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    int *pa = *(int **)a, *pb = *(int **)b;
    if (pa[0] == pb[0]) {
        return pa[1] - pb[1];
    }
    return pa[0] - pb[0];
}

int* findingUsersActiveMinutes(int** logs, int logsSize, int* logsColSize, int k, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * k);
    memset(res, 0, sizeof(int) * k);
    qsort(logs, logsSize, sizeof(int *), cmp);
    for (int i = 0; i < logsSize; ) {
        int id = logs[i][0], cnt = 0;
        while (i < logsSize && logs[i][0] == id) {
            int time = logs[i][1];
            while (i < logsSize && logs[i][0] == id && logs[i][1] == time) i++;
            cnt++;
        }
        res[cnt - 1]++;
    }

    *returnSize = k;
    return res;
}