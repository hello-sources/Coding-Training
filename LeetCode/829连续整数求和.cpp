class Solution {
public:
    using ll = long long;
    int consecutiveNumbersSum(int n) {
        // 等差数列求和：(from + to) * (to - from + 1) / 2 == n
        int res = 0;
        // 枚举长度.
        ll len = sqrt(2*n), to;
        while(len){
            // 看是否有解。求满足sum >= n的最小左端点
            ll l = 1, r = n - len + 1, m;
            while(l < r){
                m = l + r >> 1;
                if ((m+m+len-1)*len >= 2*n) r = m;
                else l = m + 1;
            }
            if ((l+l+len-1)*len == 2*n) res ++;
            len --;
        }
        return res;
    }
};