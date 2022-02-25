typedef struct {
    int *num;
    int cnt;
} SparseVector;


SparseVector* sparseVectorCreate(int* nums, int numsSize) {
    SparseVector *obj = (SparseVector *)malloc(sizeof(SparseVector));
    obj->num = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        obj->num[i] = nums[i];
    }
    obj->cnt = numsSize;
    return obj;
}

// Return the dotProduct of two sparse vectors
int sparseVectordotProduct(SparseVector* obj, SparseVector* vec) {
    int ans = 0;
    for (int i = 0; i < obj->cnt; i++) {
        ans += obj->num[i] * vec->num[i];
    }
    return ans;
}

/**
 * Your SparseVector struct will be instantiated and called as such:
 * SparseVector* v1 = sparseVectorCreate(nums1, nums1Size);
 * SparseVector* v2 = sparseVectorCreate(nums2, nums2Size);
 * int ans = sparseVectordotProduct(v1, v2);
*/