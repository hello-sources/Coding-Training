int countMaxOrSubsets(int* nums, int numsSize){
    int cnt = 0, max = INT_MIN;
    for (int i = 1; i < (1 << numsSize); i++) {
        int temp = 0;
        for (int j = 0; j < numsSize; j++) {
            if (i & (1 << j)) temp |= nums[j];
        }
        if (temp == max) cnt++;
        else if (temp > max) {
            max = temp;
            cnt = 1;
        }
    }
    return cnt;
}