int numSpecial(int** mat, int matSize, int* matColSize){
    int cnt = 0;
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[0]; j++) {
            if (!mat[i][j]) continue;
            int flag = 0;
            for (int k = 0; k < matSize; k++) {
                if (mat[k][j] == 1 && k != i) flag = 1;
            }
            for (int k = 0; k < matColSize[0]; k++) {
                if (mat[i][k] == 1 && k != j) flag = 1;
            }
            if (flag == 0) cnt++;
        }
    }
    return cnt;
}