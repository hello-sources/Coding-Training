bool isPowerOfTwo(int n){
    if (n == 1) return true;
    return n > 0 && (n & (n - 1)) == 0;
}