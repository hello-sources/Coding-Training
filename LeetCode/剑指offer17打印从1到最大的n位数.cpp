/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* printNumbers(int n, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * pow(10, n));
    int i, cnt = 0;
    for (i = 1; i < pow(10, n); i++) res[cnt++] = i;
    *returnSize = cnt;
    return res;
}