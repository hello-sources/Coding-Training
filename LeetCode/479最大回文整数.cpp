class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        int right = pow(10, n) - 1;
        for (int left = right; left >= 0; left--) {
            long temp = left;
            for (int i = left; i > 0; i /= 10) {
                temp = temp * 10 + i % 10;
            }
            for (long i = right; i * i >= temp; i--) {
                if (temp % i == 0) {
                    return temp % 1337;
                }
            }
        }
        return -1;
    }
};