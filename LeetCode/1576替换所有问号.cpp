char * modifyString(char * s){
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '?') {
            char temp = 'a';
            while ((i > 0 && s[i - 1] == temp) || (s[i + 1] != '\0' && temp == s[i + 1])) {
                ++temp;
            }
            s[i] = temp;
        }
    }
    return s;
}