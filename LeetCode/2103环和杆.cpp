int countPoints(char * rings){
    int len = strlen(rings);
    int color[3][10] = {0}, cnt = 0;
    for (int i = 0; i < len - 1; i += 2) {
        if (rings[i] == 'R') {
            color[0][rings[i + 1] - '0']++;
        } else if (rings[i] == 'G') {
            color[1][rings[i + 1] - '0']++;
        } else {
            color[2][rings[i + 1] - '0']++;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (color[0][i] > 0 && color[1][i] > 0 && color[2][i] > 0) cnt++;
    }
    return cnt;
}