int searchInsert(int* nums, int numsSize, int target){
    int head = 0, tail = numsSize, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (target == nums[mid]) return mid;
        if (target < nums[mid]) tail = mid;
        else head = mid + 1;
    }
    return head == numsSize ? numsSize : head;
}