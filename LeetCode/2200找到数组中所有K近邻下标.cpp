/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findKDistantIndices(int* nums, int numsSize, int key, int k, int* returnSize){
    int num[1005] = {0};
    *returnSize = 0;
    int *res = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        int ind = i, l = i, r = i;
        if (nums[i] == key) {
            while (l >= 0) {
                if (fabs(l - ind) <= k) num[l]++;
                l--;
            }
            while (r < numsSize) {
                if (fabs(r - ind) <= k) num[r]++;
                r++; 
            }
        }
    }
    for (int i = 0; i < 1005; i++) {
        if (num[i] > 0) res[(*returnSize)++] = i;
    }
    return res;
}