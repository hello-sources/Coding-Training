/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize){
    int num[3][101];
    memset(num, 0, sizeof(num));
    *returnSize = 0;
    for (int i = 0; i < nums1Size; i++) num[0][nums1[i]] = 1;
    for (int i = 0; i < nums2Size; i++) num[1][nums2[i]] = 1;
    for (int i = 0; i < nums3Size; i++) num[2][nums3[i]] = 1;
    int *res = (int *)malloc(sizeof(int) * 101);
    for (int i = 0; i < 101; i++) {
        if (num[0][i] + num[1][i] + num[2][i] >= 2) res[(*returnSize)++] = i;
    }
    return res;
}