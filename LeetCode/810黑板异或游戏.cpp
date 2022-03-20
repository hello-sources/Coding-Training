bool xorGame(int* nums, int numsSize){
    if (numsSize % 2 == 0) return true;
    int num = 0;
    for (int i = 0; i < numsSize; i++) num ^= nums[i];
    return num == 0;
}