int oddCells(int m, int n, int** indices, int indicesSize, int* indicesColSize){
    int cnt = 0;
    int **num = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++) {
        num[i] = (int *)malloc(sizeof(int) * n);
        memset(num[i], 0, sizeof(int) * n);
    }
    for (int i = 0; i < indicesSize; i++) {
        int a = indices[i][0], b = indices[i][1];
        for (int k = 0; k < m; k++) num[k][b]++;
        for (int k = 0; k < n; k++) num[a][k]++;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (num[i][j] % 2 != 0) cnt++;
        }
    }
    for (int i = 0; i < m; i++) free(num[i]);
    free(num);
    return cnt;
}