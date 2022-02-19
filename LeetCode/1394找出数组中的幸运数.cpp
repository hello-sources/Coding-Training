int findLucky(int* arr, int arrSize){
    int num[501] = {0};
    for (int i = 0; i < arrSize; i++) {
        num[arr[i]]++;
    }
    for (int i = 500; i > 0; i--) {
        if (num[i] == i) return i;
    }
    return -1;
}