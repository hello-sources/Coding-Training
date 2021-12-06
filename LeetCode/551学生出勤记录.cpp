bool checkRecord(char * s){
    int cntA = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'A') cntA++;
        if (cntA >= 2) return false;
        if (i - 1 >= 0 && i - 2 >= 0 && s[i] == 'L' && s[i - 1] == 'L' && s[i - 2] == 'L') return false;
    }
    return true;
}