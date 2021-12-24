void rotate(int* nums, int numsSize, int k){
    int *res = (int *)malloc(sizeof(int) * (numsSize + 1));
    int cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        res[(i + k) % numsSize] = nums[i];  
    }
    for (int i = 0; i < numsSize; i++) {
        nums[i] = res[i];
    }
    free(res);
    return ;
}