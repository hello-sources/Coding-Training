int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int countGoodRectangles(int** rectangles, int rectanglesSize, int* rectanglesColSize){
    int ans = 0, cnt = 0;
    int *num = (int *)malloc(sizeof(int) * rectanglesSize);
    memset(num, 0, sizeof(int) * rectanglesSize);
    for (int i = 0; i < rectanglesSize; i++) {
        num[cnt++] = fmin(rectangles[i][0], rectangles[i][1]);
    }
    if (rectanglesSize == 1) return num[0];
    qsort(num, cnt, sizeof(int), cmp);
    for (int i = 0; i < cnt; i++) {
        if (i == 0) ans = 1;
        else if (num[i] == num[i - 1]) {
            ans++;
            continue;
        } else break;
    }
    return ans;
}