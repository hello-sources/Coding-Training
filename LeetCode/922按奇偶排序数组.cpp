/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize){
    int *ans = (int *)malloc(sizeof(int) * numsSize);
    int *ret = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int i = 0, j = 0;
    for (int k = 0; k < numsSize; k++) {
        if (nums[k] % 2 == 0) ans[i++] = nums[k];
        else ret[j++] = nums[k];
    }
    int k = 0, l = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) nums[i] = ans[l++];
        else nums[i] = ret[k++];
        
    }
    return nums;
}

//双指针，力扣使用宏定义有可能出错
void my_swap(int *a, int *b) { 
    int t = *a;
    *a = *b;
    *b = t; 
 }

int* sortArrayByParityII(int* nums, int numsSize, int* returnSize){
    int j = 1;
    for (int i = 0; i < numsSize; i += 2) {
        if (nums[i] % 2 == 1) {
            while (nums[j] % 2 == 1) {
                j += 2;
            }
            my_swap(nums + i, nums + j);
        }
    }
    *returnSize = numsSize;
    return nums;
}