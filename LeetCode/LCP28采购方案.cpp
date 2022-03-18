int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int purchasePlans(int* nums, int numsSize, int target){
    qsort(nums, numsSize, sizeof(int), cmp);
    int l = 0, r = numsSize -1;
    long cnt = 0;
    while (l <= r) {
        if (nums[l] + nums[r] <= target) {
            cnt += r - l;
            cnt %= 1000000007;
            l++;
        } else {
            r--;
        }
    }
    return cnt % 1000000007;
}