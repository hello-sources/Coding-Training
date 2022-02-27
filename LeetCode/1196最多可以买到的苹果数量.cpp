int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
} 

int maxNumberOfApples(int* weight, int weightSize){
    qsort(weight, weightSize, sizeof(int), cmp);
    int cnt = 0, sum = 0;
    for (int i = 0; i < weightSize; i++) {
        if (sum + weight[i] <= 5000) {
            cnt++;
            sum += weight[i];
        }
    }
    return cnt;
}