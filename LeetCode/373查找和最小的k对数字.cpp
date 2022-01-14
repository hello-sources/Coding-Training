/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_N 1000005
struct pair {
    int num[2];
    int sum;
} pair[MAX_N];

int cmp(const void *a, const void *b) {
    struct pair *_a = (struct pair *)a;
    struct pair *_b = (struct pair *)b;
    return _a->sum - _b->sum; 
}

int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes){
    int len1, len2, top = 0;
    int **res = (int **)malloc(sizeof(int *) * k);
    for (int i = 0; i < k; i++) {
        res[i] = (int *)malloc(sizeof(int) * 2);
    } 
    len1 = k > nums1Size ? nums1Size : k;
    len2 = k > nums2Size ? nums2Size : k;
    *returnSize = fmin(len1 * len2, k);
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = 2;
    }
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            pair[top].sum = nums1[i] + nums2[j];
            pair[top].num[0] = nums1[i];
            pair[top++].num[1] = nums2[j];
        }
    }
    qsort(pair, top, sizeof(struct pair), cmp);
    for (int i = 0; i < (*returnSize); i++) {
        res[i][0] = pair[i].num[0];
        res[i][1] = pair[i].num[1];
    }
    return res;
}