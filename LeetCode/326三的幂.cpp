bool isPowerOfThree(int n){
    if (n < 1) return false;
    if (n == 1) return true;
    if (n % 3 == 0) return isPowerOfThree(n / 3);
    return false;
}

bool isPowerOfThree(int n){
    while (n != 0 && n % 3 == 0) {
        n /= 3;
    }
    return n == 1;
}