/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * nums1Size);
    *returnSize = nums1Size;
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] != nums2[j]) continue;
            int k;
            for (k = j + 1; k < nums2Size; k++) {
                if (nums2[k] <= nums1[i]) continue;
                res[i] = nums2[k]; 
                break;
            }
            if (k == nums2Size) {
                res[i] = -1;
                break;
            }
        }
    }
    return res;
}