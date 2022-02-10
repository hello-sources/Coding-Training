/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_FRACTION_LEN 10

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

char ** simplifiedFractions(int n, int* returnSize) {
    char ** ans = (char **)malloc(sizeof(char *) * n * (n - 1) / 2 );
    int pos = 0;
    for (int denominator = 2; denominator <= n; denominator++) {
        for (int numerator = 1; numerator < denominator; numerator++) {
            if (gcd(numerator, denominator) == 1) {
                ans[pos] = (char *)malloc(sizeof(char) * MAX_FRACTION_LEN);
                snprintf(ans[pos++], MAX_FRACTION_LEN, "%d%c%d", numerator, '/', denominator);
            }
        }
    }
    *returnSize = pos;
    return ans;
}