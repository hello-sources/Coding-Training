

int getMaxLen(int* nums, int numsSize){
    int pos = 0, neg = 0;
    if (nums[0] > 0) pos = 1;
    if (nums[0] < 0) neg = 1;
    int ret = pos;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > 0) {
            pos++;
            neg = neg > 0 ? neg + 1 : 0;
        } else if (nums[i] < 0) {
            int temp = pos;
            pos = neg > 0 ? neg + 1 : 0;
            neg = temp + 1;
        } else {
            pos = neg = 0;
        }
        ret = fmax(ret, pos);
    }
    return ret;
}