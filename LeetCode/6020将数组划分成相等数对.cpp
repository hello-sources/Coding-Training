bool divideArray(int* nums, int numsSize){
    int num[505] = {0}, cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        num[nums[i]]++;
    }
    for (int i = 0; i < 505; i++) {
        if (num[i] % 2) return false;
    }
    return true;
}