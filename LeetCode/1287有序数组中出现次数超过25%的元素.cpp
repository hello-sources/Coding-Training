int findSpecialInteger(int* arr, int arrSize){
    int i = 0;
    while (arr[i] != arr[i + arrSize / 4]) i++;
    return arr[i];
}