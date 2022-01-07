/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize){
    int max = 0;
    for (int i = 0; i < candiesSize; i++) max = fmax(max, candies[i]);
    bool *res = (bool *)malloc(sizeof(bool) * candiesSize);
    *returnSize = candiesSize;
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] + extraCandies >= max) res[i] = true;
        else res[i] = false;
    }
    return res;
} 