/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* anagramMappings(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * (nums1Size + 5));
    *returnSize = 0;
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                res[(*returnSize)++] = j;
                //nums2[j] = -1;
                break;
            }
        }
    }
    return res;
}