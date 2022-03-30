 int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (divisor == 1)
            return dividend;

        bool sign = (dividend > 0) ^ (divisor > 0) ? false : true;

        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;

        int res = 0;
        while(1) {
            int a = dividend, b = divisor, c = 1;
            if (a > b)
                break;
            while(a - b <= b) {
                c += c;
                b += b;
            }
            res += c;
            dividend -= b;
        }
        if (!sign)
            return -res;
        return res;
}