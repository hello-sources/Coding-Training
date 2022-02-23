bool findRotation(int** mat, int n, int* matColSize, int** target, int targetSize, int* targetColSize){
    int cnt = 0;
    for (int k = 0; k < 4; k++) {
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < (n + 1) / 2; j++) {
                int temp = mat[i][j];
                mat[i][j] = mat[n-1-j][i];
                mat[n-1-j][i] = mat[n-1-i][n-1-j];
                mat[n-1-i][n-1-j] = mat[j][n-1-i];
                mat[j][n-1-i] = temp;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == target[i][j]) cnt++;
            }
        }
        if (cnt == n * n) return true;
        else cnt = 0;
    }
    return false;
}