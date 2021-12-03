char * kthDistinct(char ** arr, int arrSize, int k){
    char **temp = (char **)malloc(sizeof(char *) * arrSize);
    int cnt = 0;
    if (arrSize == 1 && k == 1) return arr[0];
    for (int i = 0; i < arrSize; i++) {
        int flag = 0;
        for (int j = 0; j < arrSize; j++) {
            if (strcmp(arr[i], arr[j]) == 0) {
                flag += 1;
            }
        }
        if (flag > 1) continue;
        else temp[cnt++] = arr[i];
    }
    if (k > cnt) return "";
    else return temp[k - 1];
}