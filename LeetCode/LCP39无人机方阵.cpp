int minimumSwitchingTimes(int** source, int sourceSize, int* sourceColSize, int** target, int targetSize, int* targetColSize){
    int cnt = 0;
    int num[10005] = {0};
    for (int i = 0; i < sourceSize * sourceColSize[0]; i++) {
        num[source[i / sourceColSize[0]][i % sourceColSize[0]]]++;
        num[target[i / sourceColSize[0]][i % sourceColSize[0]]]--;
    }
    for (int i = 0; i < 10005; i++) {
        if (num[i] > 0) cnt += num[i];
    }
    return cnt;
}