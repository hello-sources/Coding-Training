/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int gcd(int a, int b) {
    return a % b == 0 ? b : gcd(b, a % b);
}

int* fraction(int* cont, int contSize, int* returnSize){
    int *ans = (int *)malloc(sizeof(int) * 2);
    ans[0] = 1, ans[1] = 0;
    int left = 1, right = 1;
    for (int i = contSize - 1; i >= 0; i--) {
        int temp = ans[1];
        ans[1] = ans[0];
        ans[0] = cont[i] * ans[1] + temp;
    }
   // int num = gcd(left, right);
    *returnSize = 2;
    return ans;
}