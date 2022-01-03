bool checkString(char * s){
    int lasta = 0, firstb = 0, cnta = 0, cntb = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == 'a') {
            cnta++;
            lasta = i;
        }
    }
    for (int i = 0; i < len; i++) {
        if (s[i] == 'b') {
            firstb = i;
            cntb++;
            break;
        }
    }
    if (cntb == 0) return true;
    if (cnta == 0) return true;
    return lasta < firstb ? true : false;
}