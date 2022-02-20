/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decrypt(int* code, int codeSize, int k, int* returnSize){
    *returnSize = codeSize;
    int *res = (int *)malloc(sizeof(int) * codeSize);
    memset(res, 0, sizeof(int) * codeSize);
    if (k == 0) return res;
    if (k > 0) {
        for (int i = 0; i < codeSize; i++) {
            int sum = 0, cnt = 1, j = i + 1;
            while (cnt <= k) {
                sum += code[j % codeSize];
                cnt++;
                j++;
            }
            res[i] = sum;
        }
    } else {
        for (int i = 0; i < codeSize; i++) {
            int sum = 0, cnt = 1,j = i - 1;
            while (cnt <= -k) {
                if (j < 0) j += codeSize;
                sum += code[j--];
                cnt++;
            }
            res[i] = sum;
        }
    }
    return res;
}