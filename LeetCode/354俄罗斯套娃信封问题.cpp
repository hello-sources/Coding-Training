/****************动态规划（超时）*****************/
int cmp(const void *a, const void *b) {
    int **pa = a, **pb = b;
    return (*pa)[0] == (*pb)[0] ? (*pb)[1] - (*pa)[1] : (*pa)[0] - (*pb)[0];
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    qsort(envelopes, envelopesSize, sizeof(int *), cmp);
    int dp[envelopesSize], ans = 1;
    for (int i = 0; i < envelopesSize; i++) dp[i] = 1;
    for (int i = 1; i < envelopesSize; i++) {
        for (int j = 0; j < i; j++) {
            if (envelopes[i][1] > envelopes[j][1]) dp[i] = fmax(dp[i], dp[j] + 1);
        }
        ans = fmax(dp[i], ans);
    }
    return ans;
}

/********************动态规划+二分查找优化*******************/
int cmp(const void *a, const void *b) {
    int **pa = a, **pb = b;
    return (*pa)[0] == (*pb)[0] ? (*pb)[1] - (*pa)[1] : (*pa)[0] - (*pb)[0];
}

int binary_search(int *arr, int size, int val) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (val < arr[mid]) right = mid - 1;
        else if (val > arr[mid]) left = mid + 1;
        else return mid;
    }
    if (arr[left] >= val) return left;
    return -1;
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    qsort(envelopes, envelopesSize, sizeof(int *), cmp);
    int dp[envelopesSize], size = 0;
    dp[size++] = envelopes[0][1];
    for (int i = 1; i < envelopesSize; i++) {
        int temp = envelopes[i][1];
        if (temp > dp[size - 1]) dp[size++] = temp;
        else dp[binary_search(dp, size, temp)] = temp;
    }
    return size;
}