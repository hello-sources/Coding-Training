int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int minimumSum(int num){
    int digit[4];
    for (int i = 0; i < 4; i++) {
        digit[i] = num % 10;
        num /= 10;
    }
    qsort(digit, 4, sizeof(digit[0]), cmp); /* 排序 */
    return (digit[0] + digit[1]) * 10 + digit[2] + digit[3]; /* 贪心输出 */
}