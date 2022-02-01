int sumOfUnique(int* nums, int numsSize){
    int num[105] = {0}, ans = 0;
    for (int i = 0; i < numsSize; i++) {
        num[nums[i]]++;
    }
    for (int i = 0; i < 105; i++) {
        if (num[i] == 1) ans += i;
    }
    return ans;
}