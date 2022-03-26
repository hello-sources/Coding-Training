bool canThreePartsEqualSum(int* arr, int arrSize){
    int sum = 0, num  = 0;
    for (int i = 0; i < arrSize; i++) sum += arr[i];
    if (sum % 3 != 0) return false;
    num = sum / 3;
    int temp = 0, temp2 = 0;
    for (int i = 0; i < arrSize - 2; i++) {
        temp += arr[i];
        if (temp == num) {
            for (int j = i + 1; j < arrSize - 1; j++) {
                temp2 += arr[j];
                if (temp2 == temp) return true;
            }
        }
    }
    return false;
}