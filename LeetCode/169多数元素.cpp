int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int majorityElement(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums[numsSize / 2];
}

//用栈模拟，最后剩下的肯定是结果
int majorityElement(int* nums, int numsSize){
    int *stack = (int *)malloc(sizeof(int) * numsSize);
    int top = -1; 
    for (int i = 0; i < numsSize; i++) {
        if (top == -1) stack[++top] = nums[i];
        else if (stack[top] == nums[i]) {
            stack[++top] = nums[i];
        } else {
            top--;
        }
    }
    return stack[0];
}