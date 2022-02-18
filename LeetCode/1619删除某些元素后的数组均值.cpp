int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

double trimMean(int* arr, int arrSize){
    qsort(arr, arrSize, sizeof(int), cmp);
    int cnt = arrSize / 20;
    double sum = 0;
    for (int i = cnt; i < arrSize - cnt; i++) {
        sum += arr[i];
    }
    return sum / (arrSize - 2 * cnt);
}