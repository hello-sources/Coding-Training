bool canFormArray(int* arr, int arrSize, int** pieces, int piecesSize, int* piecesColSize){
    int map[101] = {0};
    for (int i = 0; i < arrSize; i++) {
        map[arr[i]] = i + 1;
    }
    for (int i = 0; i < piecesSize; i++) {
        for (int j = 0; j < piecesColSize[i]; j++) {
            if (map[pieces[i][j]] == 0) return false;
            if (j > 0) {
                int x = map[pieces[i][j]] - map[pieces[i][j - 1]];
                if (x != 1) return false;
            }
        }
    }
    return true;
}