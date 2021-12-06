bool isPalindrome(int x){
    if (x < 0) return false;
    if (x == 0) return true;
    int n = x, temp = 0;
    long result = 0;
    while (x) {
        temp = x % 10;
        x /= 10;
        result = result * 10 + temp;
    }
    return result == n;
}