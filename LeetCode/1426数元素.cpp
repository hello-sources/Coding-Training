int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int countElements(int* arr, int arrSize){
    int hash[1005] = {0}, cnt = 0;
    qsort(arr, arrSize, sizeof(int), cmp);
    for (int i = 0; i < arrSize; i++) {
        hash[arr[i]]++;
    }
    for (int i = 0; i < 1004; i++) {
        if (hash[i] != 0 && hash[i + 1] != 0) cnt += hash[i];
    }
    return cnt;
}