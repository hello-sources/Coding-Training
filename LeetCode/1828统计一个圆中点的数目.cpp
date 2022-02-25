/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int get_dis(int x1, int y1, int x2, int y2) {
    int x = fabs(x1 - x2);
    int y = fabs(y1 - y2);
    return x * x + y * y;
}

int* countPoints(int** points, int pointsSize, int* pointsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * (queriesSize + 5));
    memset(res, 0, sizeof(int) * (queriesSize + 5));
    *returnSize = 0;
    for (int i = 0; i < queriesSize; i++) {
        for (int j = 0; j < pointsSize; j++) {
            int dis = get_dis(points[j][0], points[j][1], queries[i][0], queries[i][1]);
            if (queries[i][2] * queries[i][2] >= dis) res[(*returnSize)]++;
        }
        (*returnSize)++;
    }
    return res;
}