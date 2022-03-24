bool check(int *num, int n) {
    if (num[2 * n] == 1) return true;
    if (n % 2 == 0 && num[n / 2] == 1) {
        return true;
    }
    num[n] = 1;
    return false;
}

bool checkIfExist(int* arr, int arrSize){
    int num1[2010] = {0};
    int num2[2010] = {0};
    for (int i = 0; i < arrSize; i++) {
        int temp = arr[i];
        if (temp > 0) {
            if (check(num1, temp)) return true;
        } else {
            if (check(num2, fabs(temp))) return true;
        }
    }
    return false;
}

/***********************暴力效果好点********************/
bool checkIfExist(int* arr, int arrSize){
    for (int i = 0; i < arrSize; i++) {
        int num = arr[i];
        for (int j = 0; j < arrSize; j++) {
            if (num * 2 == arr[j] && i != j) return true;
        }
    }
    return false;
}