int minCount(int* coins, int coinsSize){
    int ans = 0;
    for (int i = 0; i < coinsSize; i++) {
        ans += ceil(1.0 * coins[i] / 2);
    }
    return ans;
}