int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int cmp1(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int minProductSum(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int ans = 0;
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp1);
    for (int i = 0; i < nums2Size; i++) {
        ans += nums2[i] * nums1[i];
    }
    return ans;
}