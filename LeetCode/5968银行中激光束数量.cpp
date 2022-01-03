int numberOfBeams(char ** bank, int bankSize){
    // int *num = (int *)malloc(sizeof(int) * (bankSize + 5));
    // int *temp = (int *)malloc(sizeof(int) * (bankSize + 5));
    // memset(temp, 0, sizeof(temp));
    // memset(num, 0, sizeof(num));
    int num[bankSize + 5];
    int temp[bankSize + 5];
    memset(temp, 0, sizeof(temp));
    memset(num, 0, sizeof(num));
    int ans = 0, cnt = 0;
    for (int i = 0; i < bankSize; i++) {
        for (int j = 0; bank[i][j] != '\0'; j++) {
            if (bank[i][j] == '1') num[i]++;
        }
    }
    for (int i = 0; i < bankSize; i++) {
        if (num[i] != 0) temp[cnt++] = num[i];
    }
    if (cnt == 1) return 0;
    for (int i = 1; i < cnt; i++) ans += (temp[i] * temp[i - 1]);
    // free(num);
    // free(temp);
    return ans;
}