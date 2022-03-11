int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize){
    int num[pointsSize];
    memset(num, 0, sizeof(num));
    for (int i = 0; i < pointsSize; i++) {
        num[i] = points[i][0];
    }
    qsort(num, pointsSize, sizeof(int), cmp);
    int max = INT_MIN;
    for (int i = 1; i < pointsSize; i++) {
        max = fmax(max, num[i] - num[i - 1]);
    }
    return max;
}