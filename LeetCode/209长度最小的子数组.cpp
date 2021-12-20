int minSubArrayLen(int target, int* nums, int numsSize){
    int ans = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        int sum = 0;
        for (int j = i; j < numsSize; j++) {
            sum += nums[j];
            if (sum >= target) {
                ans = fmin(ans, j - i + 1);
                break;
            }
        }
    }
    return ans == INT_MAX ? 0 : ans; 
}

/************前缀和+二分查找**********/
int binary_search(int *num, int numsSize, int target) {
    if (num[numsSize] < target) return -1;
    int l = 1, r = numsSize;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (num[mid] >= target) r = mid;
        else l = mid + 1;
    }
    return l;
}

int minSubArrayLen(int target, int* nums, int numsSize){
    int *sum = (int *)malloc(sizeof(int) * (numsSize + 5));
    int ans = INT_MAX;
    for (int i = 1; i <= numsSize; i++) {
        sum[i] = sum[i - 1] + nums[i - 1];
    }
    for (int i = 1; i <= numsSize; i++) {
        int temp = target + sum[i - 1];
        int ret = binary_search(sum, numsSize, temp);
        if (ret != -1) {
            ans = fmin(ans, ret - (i - 1));
        }
    }
    free(sum);
    return ans == INT_MAX ? 0 : ans;
}

/***********************滑动窗口************************/
int minSubArrayLen(int target, int* nums, int numsSize){
    int sum = 0, start = 0, end = 0, ans = INT_MAX;
    while (end < numsSize) {
        sum += nums[end];
        while (sum >= target) {
            ans = fmin(ans, end - start + 1);
            sum -= nums[start];
            start++;
        }
        end++;
    }
    return ans == INT_MAX ? 0 : ans;
}