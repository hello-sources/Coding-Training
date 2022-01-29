/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int judge(int num) {
    int temp = num;
    while (temp) {
        int temp1 = temp % 10;
        if (temp1 == 0 || (temp1 != 0 && num % temp1)) return 0;
        temp /= 10;
    }
    return 1;
}

int* selfDividingNumbers(int left, int right, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * (right - left + 5));
    *returnSize = 0;
    for (int i = left; i <= right; i++) {
        if (judge(i)) res[(*returnSize)++] = i;
    }
    return res;
}