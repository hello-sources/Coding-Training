int subtractProductAndSum(int n){
    int l = 1, r = 0;
    while (n) {
        l *= n % 10;
        r += n % 10;
        n /= 10;
    }
    return l - r;
}