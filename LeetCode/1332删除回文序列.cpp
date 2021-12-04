int removePalindromeSub(char * s){
    int len = strlen(s);
    int l = 0, r = len - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            return 2;
        }
        l++;
        r--;
    }
    return 1;
}