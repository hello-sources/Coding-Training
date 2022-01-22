int diagonalSum(int** mat, int matSize, int* matColSize){
    int ans = 0;
    if (matSize == 1) return mat[0][0];
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matSize; j++) {
            if (i == j || i + j == matSize - 1) ans += mat[i][j];
        }
    }
    return ans;
}