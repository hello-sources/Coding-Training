bool judge(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
char * removeVowels(char * s){
    int ind = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (!judge(s[i])) {
            s[ind++] = s[i];
        }
    }
    s[ind] = '\0';
    return s;
}