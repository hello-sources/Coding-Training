/**
 * 左指针指向当前已经处理好的序列的尾部，右指针指向待处理序列的头部。
 * 右指针不断向右移动，每次右指针指向非零数，则将左右指针对应的数交换，同时左指针右移。
 * **/
void swap(int *a, int *b) {
    int t = *a;
    *a = *b, *b = t;
}

void moveZeroes(int* nums, int numsSize){
    int left = 0, right = 0;
    while (right < numsSize) {
        if (nums[right]) {
            swap(nums + left, nums + right);
            left++;
        }
        right++;
    }
    return ;
}

/**********************************/
void moveZeroes(int* nums, int numsSize){
    int j = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) nums[j++] = nums[i];
    }
    for (int i = j; i < numsSize; i++) nums[i] = 0;
    return ;
}