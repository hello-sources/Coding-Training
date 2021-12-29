/***********暴力法**************/
int maxProfit(int* prices, int pricesSize){
    int profit = 0;
    for (int i = 0; i < pricesSize; i++) {
        for (int j = i + 1; j < pricesSize; j++) {
            profit = fmax(profit, prices[j] - prices[i]);
        }
    }
    return profit;
}

/***********一次遍历**************/
int maxProfit(int* prices, int pricesSize){
    int min = INT_MAX, max = 0;
    for (int i = 0; i < pricesSize; i++) {
        if (min > prices[i]) min = prices[i];
        else if (prices[i] - min > max) {
            max = prices[i] - min;
        }
    }
    return max;
}