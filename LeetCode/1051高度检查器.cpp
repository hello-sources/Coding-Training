int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int heightChecker(int* heights, int heightsSize){
    int cnt = 0;
    int *nums = (int *)malloc(sizeof(int) * heightsSize);
    for (int i = 0; i < heightsSize; i++) {
        nums[i] = heights[i];
    }
    qsort(nums, heightsSize, sizeof(int), cmp);
    for (int i = 0; i < heightsSize; i++) {
        if (nums[i] != heights[i]) cnt++;
    }
    return cnt;
}