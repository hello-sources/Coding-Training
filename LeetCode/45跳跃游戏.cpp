int jump(int* nums, int numsSize){
    int max = 0, ans = 0, end = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        if (max >= i) {
            max = fmax(max, i + nums[i]);
            if (i == end) {
                end = max;
                ans++;
            }
        }
    }
    return ans;
}