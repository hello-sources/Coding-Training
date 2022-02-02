bool canBeEqual(int* target, int targetSize, int* arr, int arrSize){
    int cmp1[1005] = {0}, cmp2[1005] = {0};
    for (int i = 0; i < targetSize; i++) cmp1[target[i]]++;
    for (int i = 0; i < arrSize; i++) cmp2[arr[i]]++;
    for (int i = 0; i < 1005; i++) {
        if (cmp1[i] != cmp2[i]) return false;
    }
    return true;
}