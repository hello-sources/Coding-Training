int leastMinutes(int n){
    if (n == 1) return n;
    int temp = 1, times = 1;
    while (temp < n) {
        temp *= 2;
        times++;
    }
    return times;
}