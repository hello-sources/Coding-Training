/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 总的来说，就是把左边的乘在一起，然后把右边的乘在一起，最后两边乘在一起
 */
int* constructArr(int* a, int aSize, int* returnSize){
    if (a == NULL || aSize < 2) {
        *returnSize = 0;
        return a;
    }
    int *res = (int *)malloc(sizeof(int) * aSize);
    memset(res, 0, sizeof(int) * aSize);
    int ans = a[0], cnt = 1;
    res[0] = 1;
    for (int i = 1; i < aSize; i++) res[i] = res[i - 1] * a[i - 1];
    for (int i = aSize - 2; i >= 0; --i) {
        cnt *= a[i + 1];
        res[i] *= cnt;
    }
    *returnSize = aSize;
    return res;
}