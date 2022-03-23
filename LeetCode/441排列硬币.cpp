int arrangeCoins(int n){
    int cnt = 0, ind = 1;
    while (n >= 0) {
        if (n >= ind) cnt++; 
        n -= ind;
        ind++;
    }
    return cnt;
}