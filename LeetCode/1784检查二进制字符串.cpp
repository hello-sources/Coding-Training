bool checkOnesSegment(char * s){
    int len = strlen(s);
    int i = 1;
    while (s[i]) {
        if (s[i] == '1' && s[i - 1] == '0') return false;
        i++;
    }
    return true;
}