/**
 * 
 * @param n int整型 
 * @return int整型
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */

//超级常规解决办法
int Fibonacci(int n ) {
    // write code here
    if (n == 1 || n == 2) return 1;
    else return Fibonacci(n - 1) + Fibonacci(n - 2);
}

//动规解决办法
int Fibonacci(int n ) {
    // write code here
    int a = 1, b = 1, c = 1;
    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

//或者说
int Fibonacci(int n ) {
    // write code here
    int dp[50] = {0};
    dp[1] = 1, dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}