int wiggleMaxLength(int* nums, int numsSize){
    if (numsSize < 2) return numsSize;
    int up[numsSize], down[numsSize];
    memset(up, 0, sizeof(up));
    memset(down, 0, sizeof(down));
    up[0] = down[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < nums[i - 1]) {
            up[i] = up[i - 1];
            down[i] = fmax(up[i - 1] + 1, down[i - 1]);
        } else if (nums[i] > nums[i - 1]) {
            up[i] = fmax(up[i - 1], down[i - 1] + 1);
            down[i] = down[i - 1];
        } else {
            down[i] = down[i - 1];
            up[i] = up[i - 1];
        }
    }
    return fmax(down[numsSize - 1], up[numsSize - 1]);
}