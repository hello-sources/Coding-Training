int cmp(const void *a, const void *b) {
    return *(int *)b > *(int *)a;
}

int thirdMax(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    long cnt = 1, temp = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != temp) {
            temp = nums[i];
            cnt++;
        }
        if (cnt == 3) break;
    }
    if (cnt < 3) return nums[0];
    return temp;
}