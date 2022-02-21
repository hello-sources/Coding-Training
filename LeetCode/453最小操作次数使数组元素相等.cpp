/******************超时*****************/
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int minMoves(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    if (numsSize == 2) return fabs(nums[0] - nums[1]);
    if (nums[0] == nums[numsSize - 1]) return 0;
    int cnt = 0;
    while (nums[0] != nums[numsSize - 1]) {
        int max = nums[numsSize - 1];
        for (int i = 0; i < numsSize - 1; i++) {
            nums[i]++;
        }
        cnt++;
        qsort(nums, numsSize, sizeof(int), cmp);
    }
    return cnt;
}

/*************什么叫逻辑********/
/*
    n - 1个数字加上1等于一个数字减去1的效果
*/
int minMoves(int* nums, int numsSize){
    int min = INT_MAX, cnt = 0;
    for (int i = 0; i < numsSize; i++) min = fmin(min, nums[i]);
    for (int i = 0; i < numsSize; i++) {
        cnt += nums[i] - min;
    }
    return cnt;
}