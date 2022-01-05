void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = m - 1, j = n - 1;
    int size = m + n - 1;
    while (i >= 0 || j >= 0) {
        if (i == -1) {
            nums1[size--] = nums2[j--];
        } else if (j == -1) {
            nums1[size--] = nums1[i--];
        } else if (nums1[i] > nums2[j]) {
            nums1[size--] = nums1[i--];
        } else nums1[size--] = nums2[j--];
    }
    return ;
}