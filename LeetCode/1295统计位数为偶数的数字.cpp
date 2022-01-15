int findNumbers(int* nums, int numsSize){
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        int cnt = 0;
        while (nums[i]) {
            nums[i] /= 10;
            cnt++;
        }
        ans += cnt % 2 == 0 ? 1 : 0;
    }
    return ans;
}