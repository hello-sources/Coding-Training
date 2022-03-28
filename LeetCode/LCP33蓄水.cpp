int storeWater(int* bucket, int bucketSize, int* vat, int vatSize){
    int ans = INT_MAX, vmax = 0;
    for (int i = 0; i < vatSize; i++) {
        vmax = fmax(vmax, vat[i]);
    }
    if (!vmax) return 0;
    int sum, need, time;
    for (int i = 1; i < vmax + 1; i++) {
        sum = i;
        for (int j = 0; j < bucketSize; j++) {
            need = ceil((double)vat[j] / i);
            time = fmax(0, need - bucket[j]);
            sum += time;
        }
        ans = fmin(ans, sum);
    }
    return ans;
}