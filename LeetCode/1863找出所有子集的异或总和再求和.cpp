int subsetXORSum(int* nums, int numsSize){
    int i, j, sum;
    int res = 0;
    /* 枚举子集组合的2^n-1种可能 */
    for (i = 0; i < (1 << numsSize); i++) {
        sum = 0;
        /* 根据对应1的位置, 进行异或处理 */
        for (j = 0; j < numsSize; j++) {
            if (i & (1 << j)) {
                sum ^= nums[j];
            }
        }
        res += sum;
    }
    return res;
}

/* dfs处理 */
// void dfs(int *nums, int numsSize, int sum, int idx, int *res) {
//     if (idx == numsSize) {
//         *res += sum;
//         return;
//     }
//     /* 对每个元素, 选或不选 */
//     dfs(nums, numsSize, sum ^ nums[idx], idx + 1, res);
//     dfs(nums, numsSize, sum, idx + 1, res);
// }

// int subsetXORSum(int* nums, int numsSize){
//     int res = 0;
//     dfs(nums, numsSize, 0, 0, &res);
//     return res;
// }