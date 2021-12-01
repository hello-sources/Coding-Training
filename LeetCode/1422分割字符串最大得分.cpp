int maxScore(char * s){
    int max = 0, len = strlen(s);  
    for (int i = 1; i <= len - 1; i++) {
        int cntl = 0, cntr = 0;
        for (int j = 0; j < i; j++) {
            if (s[j] == '0') cntl++;
        }
        for (int k = i; k < len; k++) {
            if (s[k] == '1') cntr++;
        }
        max = fmax(max, cntl + cntr);
    }
    return max;
}