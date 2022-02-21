int findMaxConsecutiveOnes(int* nums, int numsSize){
    int max = 0, cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) cnt++;
        else {
            max = fmax(max, cnt);
            cnt = 0;
        }
    }
    max = fmax(max, cnt);
    return max;
}