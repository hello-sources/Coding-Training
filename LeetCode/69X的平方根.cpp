int mySqrt(int x){
    int l = 0, r = x, ans = 0;
    while (l <= r) {
        int mid = (r + l)  / 2;
        if ((long long)mid * mid <= x) {
            ans = mid;
            l = mid + 1; 
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

/***********************法二*********************/
int mySqrt(int x){
    if (x == 0) return 0;
    int ans = exp(0.5 * log(x));
    return (long long)(ans + 1) * (ans + 1) <= x ? (ans + 1) : ans;
}

