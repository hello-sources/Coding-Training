bool hasAlternatingBits(int n){
    while (n) {
        int temp = n % 2;
        n /= 2;
        if (n % 2 == temp) return false;
    }
    return true;
}