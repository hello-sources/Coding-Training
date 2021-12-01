int countSegments(char * s){
    int cnt = 0;
    for (int i = 0; s[i]; i++) {
        if ((s[i] != ' ') && (i == 0 || s[i - 1] == ' ')) cnt++;
    }
    return cnt;
}