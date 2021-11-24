/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//双指针
int** largeGroupPositions(char * s, int* returnSize, int** returnColumnSizes){
    int n = strlen(s);
    int **res = (int **)malloc(sizeof(int *) * (n / 3 + 1));
    int j = 0, index = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * (n / 3 + 1));
    for (int i = 1; i <= n; i++) {
        if (s[i] != s[j]) {
            if (i - j >= 3) {
                res[index] = (int *)malloc(sizeof(int) * 2);
                res[index][0] = j;
                res[index][1] = i - 1;
                (*returnColumnSizes)[index++] = 2;
            }
            j = i;
        }
    }
    *returnSize = index;
    return res;
}