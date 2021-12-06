/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_N 10005

int* shortestToChar(char * s, char c, int* returnSize){
    int len = strlen(s), index = 0;
    *returnSize = len;
    int *num = (int *)malloc(sizeof(int) * len);
    int indexarray[MAX_N] = {0}, temp[MAX_N] = {0};
    for (int i = 0; i < len; i++) {
        if (s[i] == c) {
            indexarray[index++] = i;
            temp[i] = 1;
        }
        num[i] = MAX_N;
    }
    for (int i = 0; i < index; i++) {
        int l = indexarray[i], r = indexarray[i];
        num[indexarray[i]] = 0;
        while (l--) {
            if (temp[l] == 1) break;
            num[l] = fmin(num[l], fabs(l - indexarray[i]));
        }
        while (r++ < (len - 1)) {
            if (temp[r] == 1) break;
            num[r] = fmin(num[r], fabs(r - indexarray[i]));
        }
    }
    return num;
}