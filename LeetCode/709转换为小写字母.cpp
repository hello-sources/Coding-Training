char * toLowerCase(char * s){
    for (int i = 0; s[i]; i++) {
        if (s[i] <= 'Z' && s[i] >= 'A') {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    return s;
}