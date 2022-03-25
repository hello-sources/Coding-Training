bool containsPattern(int* arr, int arrSize, int m, int k){
    int cnt = 0;
    for (int i = 0; i <= arrSize - m * k; i++) {
        int j;
        for (j = 0; j < m * k; j++) {
            if (arr[i + j] != arr[i + j % m]) break;
        }
        if (j == m * k) return true;
    }
    return false;
}