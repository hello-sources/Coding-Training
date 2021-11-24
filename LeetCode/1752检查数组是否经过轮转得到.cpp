bool check(int* nums, int numsSize){
    if (numsSize < 2) return true;
    int loc = 0, next;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < nums[i - 1]) {
            loc = i;
            break;
        }
    }
    int pre = nums[loc];
    for (int i = 1; i < numsSize; i++) {
        next = nums[(i + loc) % numsSize];
        if (pre > next) return false;
        pre = next;
    }
    return true;
}

//循环非递归序列，后一个数小于前一个数的次数不超过1
bool check(int* nums, int numsSize){
    int cnt = 0;
    for (int i = 1; i <= numsSize; i++) {
        if (nums[i % numsSize] < nums[i - 1] && ++cnt > 1) return false;
    }
    return true;
}