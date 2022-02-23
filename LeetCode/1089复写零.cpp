void duplicateZeros(int* arr, int arrSize){
    int i = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == 0) {
            for (int j = arrSize - 1; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            i++;
        }
    }
    return ;
}