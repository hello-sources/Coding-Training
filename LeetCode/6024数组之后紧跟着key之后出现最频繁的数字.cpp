int mostFrequent(int* nums, int numsSize, int key){
    int num[1005] = {0}, max = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] == key) num[nums[i]]++;
    }
    for (int i = 0; i < 1005; i++) {
        max = fmax(max, num[i]);
    }
    for (int i = 0; i < 1005; i++) {
        if (max == num[i]) return i;
    }
    return 0;
}