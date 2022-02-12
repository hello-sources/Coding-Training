int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d){
    int ans = 0;
    for (int i = 0; i < arr1Size; i++) {
        int flag = 1;
        for (int j = 0; j < arr2Size; j++) {
            if (fabs(arr1[i] - arr2[j]) > d) continue;
            flag = 0;
            break;
        }
        if (flag) ans++;
    }
    return ans;
}