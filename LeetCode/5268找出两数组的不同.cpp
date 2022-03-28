/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes){
    int num1[2005] = {0}, num2[2005] = {0};
    int temp1[1005] = {0}, temp2[1005] = {0};
    int size1 = 0, size2 = 0;
    for (int i = 0; i < nums1Size; i++) {
        num1[nums1[i] + 1000] = 1;
    }
    for (int i = 0; i < nums2Size; i++) {
        num2[nums2[i] + 1000] = 1;
    }
    for (int i = 0; i < 2005; i++) {
        if (num1[i] != 0 && num2[i] == 0) temp1[size1++] = i - 1000;
        else if (num1[i] == 0 && num2[i] != 0) temp2[size2++] = i - 1000;
    }
    int **res = (int **)malloc(sizeof(int *) * 5);
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++) {
        res[i] = (int *)malloc(sizeof(int) * 1005); 
    }
    (*returnColumnSizes)[0] = size1;
    (*returnColumnSizes)[1] = size2;
    *returnSize = 2; 
    for (int i = 0; i < size1; i++) {
        res[0][i] = temp1[i];
    }
    for (int i = 0; i < size2; i++) {
        res[1][i] = temp2[i];
    }
    return res;
}