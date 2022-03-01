void dfs(int **requests, int requestsSize, int n, int pos, int *delta, int *ans, int *cnt, int *zero) {
    if (pos == requestsSize) {
        if (*zero == n) {
            *ans = fmax(*ans, *cnt);
        }
        return ;
    }
    dfs(requests, requestsSize, n, pos + 1, delta, ans, cnt, zero);
    int z = *zero;
    ++*cnt;
    const int *r = requests[pos];
    int x = r[0], y = r[1];
    *zero -= delta[x] == 0;
    --delta[x];
    *zero += delta[x] == 0;
    *zero -= delta[y] == 0;
    ++delta[y];
    *zero += delta[y] == 0;
    dfs(requests, requestsSize, n, pos + 1, delta, ans, cnt, zero);
    --delta[y];
    ++delta[x];
    --*cnt;
    *zero = z;
    return ;
}

int maximumRequests(int n, int** requests, int requestsSize, int* requestsColSize){
    int *temp = (int *)malloc(sizeof(int) * n);
    memset(temp, 0, sizeof(int) * n);
    int ans = 0, cnt = 0, zero = n;
    dfs(requests, requestsSize, n, 0, temp, &ans, &cnt, &zero);
    return ans;
}