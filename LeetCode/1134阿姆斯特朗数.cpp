bool isArmstrong(int n){
    int digit = 0, temp = n, ans = 0;
    while (temp) {
        temp /= 10;
        digit++;
    }
    temp = n;
    while (temp) {
        ans += (int)pow(temp % 10, digit);
        temp /= 10;
    }
    return ans == n;
}