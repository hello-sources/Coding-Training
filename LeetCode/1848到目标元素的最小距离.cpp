int getMinDistance(int* nums, int numsSize, int target, int start){
    int min = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            min = fmin(min, abs(i - start));
        }
    }
    return min;
}