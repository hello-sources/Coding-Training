/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int num, cnt;
} Pair;

int cmp(const void *a, const void *b) {
    Pair pa = *(Pair *)a;
    Pair pb = *(Pair *)b;
    return pb.cnt - pa.cnt;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    Pair *pair = (Pair *)malloc(sizeof(Pair) * numsSize);
    int size = 0;
    memset(pair, 0, sizeof(Pair) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        int flag = 0;
        for (int j = 0; j < size; j++) {
            if (pair[j].num == nums[i]) {
                pair[j].cnt++;
                flag = 1;
            }
        }
        if (!flag) {
            pair[size].num = nums[i];
            pair[size++].cnt = 1;
        }
    }
    qsort(pair, size, sizeof(Pair), cmp);
    int *res = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    for (int i = 0; i < k; i++) {
        res[(*returnSize)++] = pair[i].num;
    }
    return res;
}