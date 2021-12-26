void reverseString(char* s, int sSize){
    for (int i = 0; i * 2 < sSize; i++) {
        char ch = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = ch;
    }
    return ;
}