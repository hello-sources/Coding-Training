typedef struct {
    int *nums;
    int left, right;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *obj = (NumArray *)malloc(sizeof(NumArray));
    obj->nums = (int *)malloc(sizeof(int) * numsSize);
    for (int i =0; i < numsSize; i++) {
        obj->nums[i] = nums[i];
    }
    obj->left = 0;
    obj->right = 0;
    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int ans = 0;
    for (int i = left; i <= right; i++) ans += obj->nums[i];
    return ans;
}

void numArrayFree(NumArray* obj) {
    free(obj->nums);
    free(obj);
    return ;
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/