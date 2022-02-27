bool canPermutePalindrome(char * s){
    int map[128] = {0}, cnt1 = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) map[s[i]]++;
    for (int i = 0; i < 128; i++) {
        if (map[i] % 2 == 0) continue;
        cnt1++;
    }
    return cnt1 > 1 ? false : true;
}