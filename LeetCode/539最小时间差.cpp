int getMin(char *s) {
    return ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 + (s[4] - '0');
}

int cmp(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int findMinDifference(char ** timePoints, int timePointsSize){
    qsort(timePoints, timePointsSize, sizeof(char *), cmp);
    int ans = 1440;
    int time0 = getMin(timePoints[0]);
    int time1 = time0;
    for (int i = 1; i < timePointsSize; i++) {
        int temp = getMin(timePoints[i]);
        ans = fmin(ans, temp - time1);
        time1 = temp;
    }
    ans = fmin(ans, time0 + 1440 - time1);
    return ans;
}