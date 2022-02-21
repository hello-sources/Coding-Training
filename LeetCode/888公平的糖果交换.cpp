/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int get_sum(int *nums, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += nums[i];
    return sum;
}

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize){
    int sumA = get_sum(aliceSizes, aliceSizesSize);
    int sumB = get_sum(bobSizes, bobSizesSize);
    int i = 0, j = 0, dif = (sumA - sumB) / 2;
    int *res = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    qsort(aliceSizes, aliceSizesSize, sizeof(int), cmp);
    qsort(bobSizes, bobSizesSize, sizeof(int), cmp);
    while (i < aliceSizesSize && j < bobSizesSize) {
        if (aliceSizes[i] - bobSizes[j] == dif) {
            res[0] = aliceSizes[i];
            res[1] = bobSizes[j];
            return res;
        } else if (aliceSizes[i] - bobSizes[j] > dif) {
            j++;
        } else {
            i++;
        }
    }
    return res;
}