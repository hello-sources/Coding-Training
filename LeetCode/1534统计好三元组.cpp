int countGoodTriplets(int* arr, int arrSize, int a, int b, int c){
    int ans = 0;
    for (int i = 0; i < arrSize - 2; i++) {
        for (int j = i + 1; j < arrSize - 1; j++) {
            for (int k = j + 1; k < arrSize; k++) {
                if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) ans++;
            }
        }
    }
    return ans;
}