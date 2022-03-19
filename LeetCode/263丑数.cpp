bool isUgly(int n){
    if (n <= 0) return false;
    int num[3] = {2, 3, 5};
    for (int i = 0; i < 3; i++) {
        while (n % num[i] == 0) {
            n /= num[i];
        }
    }
    return n == 1;
}