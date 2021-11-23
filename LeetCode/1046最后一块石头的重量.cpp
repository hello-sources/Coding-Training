#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b, b = __temp; \
}

int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int lastStoneWeight(int* stones, int stonesSize){
    if (stonesSize == 1) return stones[0];
    qsort(stones, stonesSize, sizeof(int), cmp);
    // for (int i = 0; i < stonesSize; i++) {
    //     for (int j = i + 1; j < stonesSize; j++) {
    //         if (stones[j] > stones[i]) swap(stones[j], stones[i]);
    //     }
    // }
    if (stones[1] == 0) return 0;
    stones[0] = stones[0] - stones[1];
    stones[1] = 0;
    lastStoneWeight(stones, stonesSize);
    return stones[0];
}