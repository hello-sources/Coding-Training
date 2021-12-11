/**
 * 这题得用动态规划，主要思路如下：
 * 这里定义f(i, j)表示模式串1从开始到第i个位置，以及模式串2从开始到第j个位置能否交错形成母串i+j个元素
 * 如果模式串1的第i位与母串的第i+j位相等，则能不能成就取决模式串的前i-1个元素加上模式串2的前j个元素与母串的i+j-1元素能不能组成的问题了
 * 同样的对于模式串2来说也一样，如果模式串2的第j位与母串的i+j位相等，问题规模变成前面的模式串j-1位加上模式串1的前i位能不能组成母串前i+j-1位元素的问题
 * 动态转移方程如下：
 * f(i,j)=[f(i−1,j)and s1(i−1) = s3(p)]or[f(i,j−1)and s2(j−1) = s3(p)]
*/

bool isInterleave(char * s1, char * s2, char * s3){
    int len1 = strlen(s1), len2 = strlen(s2), len3 = strlen(s3);
    if (len1 + len2 != len3) return false;
    int dp[len1 + 1][len2 + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            int ind = i + j - 1;
            if (i > 0) {
                dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[ind]);
            } 
            if (j > 0) {
                dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[ind]);
            }
        }
    }
    return dp[len1][len2];
}