int minimumMoves(char * s){ 
    int len = strlen(s);
    if (len < 3 || strstr(s, "X") == NULL) return 0;
    int i = 0, cnt = 0;
    while (i < len) {
        if (s[i] == 'X') {
            cnt++;
            i += 3;
        } else {
            i++;
        }
    }
    return cnt;
}