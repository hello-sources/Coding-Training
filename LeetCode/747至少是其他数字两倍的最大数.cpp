int dominantIndex(int* nums, int numsSize){
    int max = INT_MIN, ind;
    for (int i = 0; i < numsSize; i++) max = fmax(max, nums[i]);
    for (int i = 0; i < numsSize; i++) {
        if (max == nums[i]) {
            ind = i;
            break;
        }
    }
    if (numsSize == 1) return 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != max && nums[i] * 2 > max) return -1;
    }
    return ind;
}