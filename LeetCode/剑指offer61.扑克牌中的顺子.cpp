int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

bool isStraight(int* nums, int numsSize){
    int cnt = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize - 1; i++) {
        if (!nums[i]) cnt++;
        else if (nums[i] == nums[i + 1]) {
            return false;
        }
    }
    return nums[4] - nums[cnt] < 5;
}