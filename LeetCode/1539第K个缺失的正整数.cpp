int findKthPositive(int* arr, int arrSize, int k){
    int num[2005] = {0};
    for (int i = 0; i < arrSize; i++) {
        num[arr[i]]++;
    }
    int cnt = 0;
    for (int i = 1; i < 2005; i++) {
        if (num[i] == 0) cnt++;
        if (cnt == k) return i;
    }
    return -1;
}