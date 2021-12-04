bool isSubsequence(char * s, char * t){
    int lens = strlen(s), lent = strlen(t);
    int i = 0, j = 0;
    while (i < lens && j < lent) {
        if (s[i] == t[j]) i++;
        j++;
    }
    return i == lens;
}