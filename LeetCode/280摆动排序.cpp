#define swap(a, b) { \
    __typeof(a) __temp = a; \
    a = b; b = __temp; \
}

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void wiggleSort(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 1; i < numsSize - 1; i += 2) {
        swap(nums[i], nums[i + 1]);
    }
    return ;
}