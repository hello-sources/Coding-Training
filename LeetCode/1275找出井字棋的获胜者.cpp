char * tictactoe(int** moves, int movesSize, int* movesColSize){
    int chess[3][3] = {0};
    for (int i = 0; i < movesSize; i++) {
        int x = moves[i][0], y = moves[i][1];
        if (i & 1) chess[x][y]++;
        else chess[x][y]--;
    }
    int suma = chess[0][0] + chess[1][1] + chess[2][2];
    int sumb = chess[0][2] + chess[1][1] + chess[2][0];
    if (suma == 3 || sumb == 3) return "B";
    if (sumb == -3 || suma == -3) return "A";
    for (int i = 0; i < 3; i++) {
        suma = chess[i][0] + chess[i][1] + chess[i][2];
        sumb = chess[0][i] + chess[1][i] + chess[2][i];
        if (suma == 3 || sumb == 3) return "B";
        if (suma == -3 || sumb == -3) return "A";
    }
    return movesSize < 9 ? "Pending" : "Draw";
}