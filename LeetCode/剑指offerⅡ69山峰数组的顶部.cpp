int peakIndexInMountainArray(int* arr, int arrSize){
    int max = INT_MIN, ind = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] >= max) {
            max = arr[i];
            ind = i;
        }
    }
    return ind;
}