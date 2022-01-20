/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* dicesProbability(int n, int* returnSize){
    double *dp = (double *)malloc(sizeof(double) * 6);
    int size =  6;
    for (int i = 0; i < 6; i++) {
        dp[i] = 1.0 / 6.0;
    }
    for (int i = 2; i <= n; i++) {
        double *temp = (double *)calloc(5 * i + 1, sizeof(double));
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < 6; k++) {
                temp[j + k] += (double)dp[j] * (1.0 / 6.0);
            }
        }
        dp = (double *)realloc(dp, sizeof(double) * (5 * i + 1));
        for (int m = 0; m < 5 * i + 1; m++) dp[m] = temp[m];
        size = 5 * i + 1;
        free(temp);
    }
    *returnSize = 5 * n + 1;
    return dp;
}