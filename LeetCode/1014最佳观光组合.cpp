int maxScoreSightseeingPair(int* values, int valuesSize){
    int ans = 0, max = values[0] + 0;
    for (int i = 1; i < valuesSize; i++) {
        ans = fmax(ans, max + values[i] - i);
        max = fmax(max, values[i] + i);
    }
    return ans;
}