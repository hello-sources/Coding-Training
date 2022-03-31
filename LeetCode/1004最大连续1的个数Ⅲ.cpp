int binary_search(int *nums, int len, int target) {
    int left = 0, right = len - 1;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return left;
}

int longestOnes(int* nums, int numsSize, int k){
    int cnt[100005];
    cnt[0] = 0;
    for (int i = 1; i <= numsSize; i++) {
        cnt[i] = cnt[i - 1] + 1 - nums[i - 1];
    }
    int ans = 0;
    for (int right = 0; right < numsSize; right++) {
        int left = binary_search(cnt, numsSize + 1, cnt[right + 1] - k);
        ans = fmax(ans, right - left + 1);
    }
    return ans;
}