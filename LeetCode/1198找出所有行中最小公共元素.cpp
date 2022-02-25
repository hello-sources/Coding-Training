int smallestCommonElement(int** mat, int matSize, int* matColSize){
    int num[10005] = {0};
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[i]; j++) {
            num[mat[i][j]]++;
        }
    }
    for (int i = 0; i < 10005; i++) {
        if (num[i] == matSize) return i;
    }
    return -1;
}