bool checkPerfectNumber(int num){
    if (num == 0 || num == 1) return false;
    int ans = 1;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            ans += i;
            if (i * i < num) ans += num / i;
        }
    }
    return ans == num;
}