int sumOddLengthSubarrays(int* arr, int arrSize){
    int ans = 0;
    for (int i = 0; i < arrSize; i++) {
        for (int j = 1; i + j <= arrSize; j += 2) {
            int k = j + i - 1;
            for (int l = i; l <= k; l++) {
                ans += arr[l];
            }
        }
    }
    return ans;
}