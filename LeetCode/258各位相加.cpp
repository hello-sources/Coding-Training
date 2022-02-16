int addDigits(int num){
    while (num > 9) {
        int temp = num;
        int ans = 0;
        while (temp) {
            ans += temp % 10;
            temp /= 10;
        }
        num = ans;
    }
    return num;
}