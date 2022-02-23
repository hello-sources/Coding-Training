bool kLengthApart(int* nums, int numsSize, int k){
    int pre = -1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            if (pre != -1 && i - pre - 1 < k) return false;
            pre = i;
        }
    }
    return true;
}