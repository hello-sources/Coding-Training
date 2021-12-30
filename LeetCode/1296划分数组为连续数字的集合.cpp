int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

bool isPossibleDivide(int* nums, int numsSize, int k){
    if (numsSize % k) return false;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            int cnt = 0, pre = nums[i];
            for (int j = i; j < numsSize && cnt < k; j++) {
                if (nums[j] != pre) continue;
                pre++;
                cnt++;
                nums[j] = 0;
            }
            if (cnt < k) return false;
        }
    }
    return true;
}