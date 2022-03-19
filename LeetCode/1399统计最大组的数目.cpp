int countLargestGroup(int n){
    int nums[n + 5], max = 0, cnt = 0;
    memset(nums, 0, sizeof(nums));
    for (int i = 1; i <= n; i++) {
        int temp = 0, num = i;
        while (num) {
            temp += num % 10;
            num /= 10;
        }
        nums[temp]++;
    }
    for (int i = 0; i <= n; i++) max = fmax(max, nums[i]);
    for (int i = 0; i <= n; i++) if (max == nums[i]) cnt++;
    return cnt;
}