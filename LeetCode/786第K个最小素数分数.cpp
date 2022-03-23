/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int up, down;
} Fraction;

int cmp(const void *a, const void *b) {
    Fraction l = *(Fraction *)a;
    Fraction r = *(Fraction *)b;
    return l.up * r.down - l.down * r.up;
}

int* kthSmallestPrimeFraction(int* arr, int arrSize, int k, int* returnSize){
    int time = (arrSize - 1) * arrSize / 2; 
    Fraction *fraction = (Fraction *)malloc(sizeof(Fraction) * time);
    int cnt = 0;
    int *res = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    for (int i = 0; i < arrSize; i++) {
        for (int j = i + 1; j < arrSize; j++) {
            fraction[cnt].up = arr[i];
            fraction[cnt++].down = arr[j];
        }
    }
    qsort(fraction, cnt, sizeof(Fraction), cmp);
    res[0] = fraction[k - 1].up;
    res[1] = fraction[k - 1].down;
    return res;
}