/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_N 2005
int* arraysIntersection(int* arr1, int arr1Size, int* arr2, int arr2Size, int* arr3, int arr3Size, int* returnSize){
    int num[MAX_N] = {0};
    *returnSize = 0;
    int *res = (int *)malloc(sizeof(int) * 1005);
    for (int i = 0; i < arr1Size; i++) num[arr1[i]]++;
    for (int i = 0; i < arr2Size; i++) num[arr2[i]]++;
    for (int i = 0; i < arr3Size; i++) num[arr3[i]]++;
    for (int i = 0; i < MAX_N; i++) {
        if (num[i] != 3) continue;
        res[(*returnSize)++] = i;
    }
    return res;
}