int removeElement(int* nums, int numsSize, int val){
    int l = 0;
    for (int r = 0; r < numsSize; r++) {
        if (nums[r] != val) {
            nums[l] = nums[r];
            l++;
        }
    }
    return l;
}