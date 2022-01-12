bool increasingTriplet(int* nums, int numsSize){
    if (numsSize < 3) return false;
    int first = nums[0], second = INT_MAX;
    for (int i = 0; i <= numsSize - 1; i++) {
        int num = nums[i];
        if (num > second) return true;
        else if (num > first) second = num;
        else first = num;
    }
    return false;
}