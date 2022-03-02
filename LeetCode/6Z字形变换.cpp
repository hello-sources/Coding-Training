char * convert(char * s, int numRows){
    int len = strlen(s);
    if (numRows == 1 || numRows >= len) return s;
    int t = numRows * 2 - 2;
    int c = (len + t - 1) / t * (numRows - 1);
    char **res = (char **)malloc(sizeof(char *) * numRows);
    for (int i = 0; i < numRows; i++) {
        res[i] = (char *)malloc(sizeof(char) * c);
        memset(res[i], 0, sizeof(char) * c);
    }
    for (int i = 0, x = 0, y = 0; i < len; i++) {
        res[x][y] = s[i];
        if (i % t < numRows - 1) x++;
        else {
            x--, y++;
        }
    }
    int pos = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < c; j++) {
            if (res[i][j]) {
                s[pos++] = res[i][j];
            }
        }
        free(res[i]);
    }
    free(res);
    return s;
}