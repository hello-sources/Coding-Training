bool canBeIncreasing(int* nums, int numsSize){
    int ind = -1, cnt = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) continue;
        ind = i;
        cnt++;
    }
    if (cnt == 0) return true;
    if (cnt == 1) {
        if (ind < numsSize - 1 && ind > 1 && nums[ind - 1] >= nums[ind + 1] && nums[ind - 2] >= nums[ind]) {
            return false;
        }
        return true;
    }
    return false;
}