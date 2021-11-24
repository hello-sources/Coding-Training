/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int binary_search(int *nums, int n, int target) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) head = mid + 1;
        else tail = mid - 1; 
    }
    return -1;
}

int* arrayRankTransform(int* arr, int arrSize, int* returnSize){
    int *nums = (int *)malloc(sizeof(int) * arrSize);
    int *cnt = (int *)malloc(sizeof(int) * arrSize);
    int cal = 1;
    for (int i = 0; i < arrSize; i++) {
        nums[i] = arr[i];
        cnt[i] = 1;
    }
    qsort(nums, arrSize, sizeof(int), cmp);
    for (int i = 1; i < arrSize; i++) {
        if (nums[i] == nums[i - 1]) {
            cnt[i] = cal;
        } else {
            cnt[i] = ++cal;
        }
    }
    for (int i = 0; i < arrSize; i++) {
        arr[i] = cnt[binary_search(nums, arrSize, arr[i])];
    }
    *returnSize = arrSize;
    return arr;
}