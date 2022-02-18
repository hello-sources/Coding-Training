int findMagicIndex(int* nums, int numsSize){
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == i) return i;
    }
    return -1;
}