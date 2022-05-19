class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int mid = (left + right) >> 1;
            int cnt = mid / n * n;
            for (int i = mid  / n + 1; i <= m; i++) {
                cnt += mid / i;
            }
            if (cnt >= k) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};