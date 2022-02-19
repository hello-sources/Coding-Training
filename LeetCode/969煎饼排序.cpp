void reverse(int *arr, int arrSize) {
    for (int left = 0, right = arrSize - 1; left < right; left++, right--) {
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
    }
}

int *pancakeSort(int *arr, int arrSize, int *returnSize){
    int *ret = (int *)malloc(sizeof(int) * (arrSize - 1) * 2);
    int retSize = 0;
    for (int n = arrSize; n > 1; n--) {
        int index = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[index]) {
                index = i;
            }
        }
        if (index == n - 1) {
            continue;
        }
        reverse(arr, index + 1);
        reverse(arr, n);
        ret[retSize++] = index + 1;
        ret[retSize++] = n;
    }
    *returnSize = retSize;
    return ret;
}