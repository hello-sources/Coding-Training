
int minDeletion(int* nums, int numsSize){
    int ans = 0, flag = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        if (i % 2 == flag && nums[i] == nums[i + 1]) {
            ans++;
            flag = 1;
        }
    }
    if ((numsSize - ans) % 2) ans++;
    return ans;
}