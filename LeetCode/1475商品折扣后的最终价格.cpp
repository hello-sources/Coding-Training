/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize){
    int *res = (int *)malloc(sizeof(int) * pricesSize);
    *returnSize = 0;
    for (int i = 0; i < pricesSize; i++) {
        int temp = prices[i];
        for (int j = i + 1; j < pricesSize; j++) {
            if (prices[j] > prices[i]) continue;
            temp -= prices[j]; 
            break;
        }
        res[(*returnSize)++] = temp;
    } 
    return res;
}