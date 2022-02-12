/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct Pair {
    int num, fre;
} Pair;

int cmp(const void *a, const void *b) {
    Pair *_a = (Pair *)a;
    Pair *_b = (Pair *)b;
    if (_a->fre == _b->fre) return _b->num - _a->num;
    return _a->fre - _b->fre;
}

int* frequencySort(int* nums, int numsSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * 201);
    memset(res, 0, sizeof(int) * 201);
    for (int i = 0; i < numsSize; i++) {
        res[nums[i] + 100]++;
    }
    Pair *pair = (Pair *)malloc(sizeof(Pair) * 201);
    for (int i = 0; i < numsSize; i++) {
        pair[i].num = nums[i];
        pair[i].fre = res[nums[i] + 100];
    }
    qsort(pair, numsSize, sizeof(Pair), cmp);
    for (int i = 0; i < numsSize; i++) {
        nums[i] = pair[i].num;
    }
    free(pair);
    free(res);
    *returnSize = numsSize;
    return nums;
}