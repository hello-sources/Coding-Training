/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp1(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int cmp2(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int* sortEvenOdd(int* nums, int numsSize, int* returnSize){
    int *odd = malloc((numsSize / 2 + 1) * sizeof(int));
    int *even = malloc((numsSize / 2 + 1) * sizeof(int));
    int idx1 = 0;
    int idx2 = 0;
    
    *returnSize = numsSize;
    if (numsSize == 1) {
        return nums;
    }
    for (int i = 1; 2 * i - 1 < numsSize; i++) {
        odd[idx1++] = nums[2 * i - 1];
    }
    qsort(odd, idx1, sizeof(int), cmp2);
    for (int i = 0; 2 * i < numsSize; i++) {
        even[idx2++] = nums[2 * i];
    }
    qsort(even, idx2, sizeof(int), cmp1);
    idx1 = 0;
    idx2 = 0;
    for (int i = 1; 2 * i - 1 < numsSize; i++) {
        nums[2 * i - 1] = odd[idx1++];
    }
    for (int i = 0; 2 * i < numsSize; i++) {
        nums[2 * i] = even[idx2++];
    }
    free(odd);
    free(even);
    return nums;
}