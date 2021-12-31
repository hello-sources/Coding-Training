int translateNum(int num){
    int *nums = (int *)malloc(sizeof(int) * 15);
    int *dp = (int *)malloc(sizeof(int) * 15);
    int numsize = 0;
    while (num > 9) {
        nums[numsize++] = num % 10;
        num /= 10;
    }
    nums[numsize++] = num;
    for (int i = 0; i < numsize / 2; i++) {
        int temp = nums[i];
        nums[i] = nums[numsize - 1 - i];
        nums[numsize - 1 - i] = temp;
    }
    dp[0] = 1;
    dp[1] = (nums[0] * 10 + nums[1] < 26 && nums[0] * 10 + nums[1] > 9) ? dp[0] + 1 : dp[0];
    for (int i = 2; i < numsize; i++) {
        dp[i] = (nums[i - 1] * 10 + nums[i] < 26 && nums[i - 1] * 10 + nums[i] > 9) ? dp[i - 2] + dp[i - 1] : dp[i - 1];
    }
    free(nums);
    return dp[numsize - 1];
}