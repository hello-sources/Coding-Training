int climbStairs(int n){
    int ans = 1, first = 0, second = 0;
    for (int i = 1; i <= n; i++) {
        first = second;
        second = ans;
        ans = first + second;
    }
    return ans;
}