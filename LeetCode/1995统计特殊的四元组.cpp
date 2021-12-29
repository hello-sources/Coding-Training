int countQuadruplets(int* nums, int numsSize){
    int cnt = 0;
    for (int i = 0; i < numsSize - 3; i++) {
        for (int j = i + 1; j < numsSize - 2; j++) {
            for (int k = j + 1; k < numsSize - 1; k++) {
                for (int l = k + 1; l < numsSize; l++) {
                    if (nums[i] + nums[j] + nums[k] == nums[l]) cnt++;
                    else continue;
                }
            }
        }
    }
    return cnt;
}


/*************哈希表存储*******************/
#define MAX_N 500

int countQuadruplets(int* nums, int numsSize){
    int ans = 0;
    int *res = (int *)malloc(sizeof(int) * MAX_N);
    memset(res, 0, sizeof(int) * MAX_N);
    for (int b = numsSize - 3; b >= 1; b--) {
        for (int d = b + 2; d < numsSize; d++) {
            if (nums[d] >= nums[b + 1]) {
                res[nums[d] - nums[b + 1]]++;
            }
        }
        for (int a = 0; a < b; a++) {
            ans += res[nums[b] + nums[a]];
        }
    }
    free(res);
    return ans;
}