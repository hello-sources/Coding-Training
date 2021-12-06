char shift(char ch, int x) {
    return ch + x;
}

char * replaceDigits(char * s){
    int len = strlen(s);
    for (int i = 1; i < len; i += 2) {
        s[i] = shift(s[i - 1], s[i] - '0');
    }
    return s;
}