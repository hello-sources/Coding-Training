/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    int *res = (int *)malloc(sizeof(int) * 1002);
    *returnSize = 0;
    while (nums1Size > 0 && nums2Size > 0) {
        if (nums1[nums1Size - 1] < nums2[nums2Size - 1]) {
            nums2Size--;
        } else if (nums1[nums1Size - 1] > nums2[nums2Size - 1]) {
            nums1Size--;
        } else {
            res[(*returnSize)++] = nums2[nums2Size - 1];
            nums1Size--;
            nums2Size--;
        }
    }
    return res;
}