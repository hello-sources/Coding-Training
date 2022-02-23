#define MAX_N 40005
int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize){
    // int ind = 0, max = 0, cnt = 0;
    // int mat[MAX_N][MAX_N];
    // memset(mat, 0, sizeof(int) * MAX_N * MAX_N);
    // while (ind < opsSize) {
    //     for (int i = 0; i < ops[ind][0]; i++) {
    //         for (int j = 0; j < ops[ind][1]; j++) {
    //             mat[i][j]++;
    //             max = fmax(max, mat[i][j]);
    //         }
    //     }
    //     ind++;
    // }
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (mat[i][j] == max) cnt++;
    //     }
    // }
    // return cnt;
    int mina = m, minb = n;
    for (int i = 0; i < opsSize; i++) {
        mina = fmin(mina, ops[i][0]);
        minb = fmin(minb, ops[i][1]);
    }
    return mina * minb;
}