/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void reverse(int *nums, int *size) {
    for (int i = 0; i * 2 < (*size); i++) {
        int temp = nums[i];
        nums[i] = nums[*size - 1 - i];
        nums[*size - 1 - i] = temp;
    }
    return ;
}

int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
    int *res = (int *)malloc(sizeof(int) * (numSize + 10));
    *returnSize = 0;
    for (int i = numSize - 1; i >= 0; i--) {
        int temp = num[i] + k % 10;
        k /= 10;
        if (temp > 9) {
            k++;
            temp -= 10;
        }
        res[(*returnSize)++] = temp;
    }
    for ( ; k > 0; k /= 10) {
        res[(*returnSize)++] = k % 10;
    }
    int size = *returnSize;
    reverse(res, &size);
    return res;
}