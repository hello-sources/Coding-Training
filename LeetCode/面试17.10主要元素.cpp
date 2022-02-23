int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int majorityElement(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    int cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == nums[numsSize / 2]) cnt++;
    }
    return cnt > numsSize / 2 ? nums[numsSize / 2] : -1;
}