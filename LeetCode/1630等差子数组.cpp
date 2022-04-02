/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

bool* checkArithmeticSubarrays(int* nums, int numsSize, int* l, int lSize, int* r, int rSize, int* returnSize){
    bool *res = (bool *)malloc(sizeof(bool) * 505);
    *returnSize = 0;
    for (int i = 0; i < lSize; i++) {
        int num[505];
        memset(num, 0, sizeof(num));
        int size = 0;
        for (int j = l[i]; j <= r[i]; j++) {
            num[size++] = nums[j];
        }
        qsort(num, size, sizeof(int), cmp);
        int sum = num[1] - num[0];
        int k;
        for (k = 1; k < size; k++) {
            if (num[k] - num[k - 1] != sum) {
                res[(*returnSize)++] = false;
                break;
            }
        }
        if (k == size) res[(*returnSize)++] = true;
    }
    return res;
}