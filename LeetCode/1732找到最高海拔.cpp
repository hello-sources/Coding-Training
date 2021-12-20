int largestAltitude(int* gain, int gainSize){
    int *sum = (int *)malloc(sizeof(int) * (gainSize + 5));
    sum[0] = 0;
    int max = sum[0];
    for (int i = 0; i < gainSize; i++) {
        sum[i + 1] = sum[i] + gain[i];
        max = fmax(max, sum[i + 1]);
    }
    return max;
}