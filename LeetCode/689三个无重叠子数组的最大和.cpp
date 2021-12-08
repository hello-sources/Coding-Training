/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSumOfThreeSubarrays(int* nums, int numsSize, int k, int* returnSize){
    int sum1 = 0, totalsum1 = 0, totalsum1_ind = 0;
    int sum2 = 0, totalsum2 = 0, totalsum2_ind1 = 0, totalsum2_ind2 = 0;
    int sum3 = 0, totalsum3 = 0;
    int *res = (int *)malloc(sizeof(int) * 4);
    for (int i = 2 * k; i < numsSize; i++) {
        sum1 += nums[i - 2 * k];
        sum2 += nums[i - k];
        sum3 += nums[i];
        if (i >= 3 * k - 1) {
            if (sum1 > totalsum1) {
                totalsum1 = sum1;
                totalsum1_ind = i - 3 * k + 1;
            }
            if (totalsum1 + sum2 > totalsum2) {
                totalsum2 = totalsum1 + sum2;
                totalsum2_ind1 = totalsum1_ind;
                totalsum2_ind2 = i - 2 * k + 1;
            }
            if (totalsum2 + sum3 > totalsum3) {
                totalsum3 = totalsum2 + sum3;
                res[0] = totalsum2_ind1, res[1] = totalsum2_ind2, res[2] = i - k + 1;
            }
            sum1 -= nums[i - 3 * k + 1];
            sum2 -= nums[i - 2 * k + 1];
            sum3 -= nums[i - k + 1];
        }
    }
    *returnSize = 3;
    return res;
}