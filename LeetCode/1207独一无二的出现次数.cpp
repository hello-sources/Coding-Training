int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

bool uniqueOccurrences(int* arr, int arrSize){
    int *cnt = (int *)malloc(sizeof(int) * 2005);
    memset(cnt, 0, sizeof(int) * 2005);
    for (int i = 0; i < arrSize; i++) {
        cnt[arr[i] + 1001]++;
    }
    qsort(cnt, 2005, sizeof(int), cmp);
    for (int i = 0; i < 2004; i++) {
        if (cnt[i] != 0 && cnt[i] == cnt[i + 1]) return false;
    }
    return true;
}