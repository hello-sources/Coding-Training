int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

bool canMakeArithmeticProgression(int* arr, int arrSize){
    qsort(arr, arrSize, sizeof(int), cmp);
    int cnt = arr[1] - arr[0];
    for (int i = 2; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] == cnt) continue;
        else return false; 
    }
    return true;
}