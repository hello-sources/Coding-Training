bool canPermutePalindrome(char* s){
    int len = strlen(s), num[128] = {0}, cnt0 = 0, cnt1 = 0;
    for (int i = 0; s[i]; i++) {
        num[s[i]]++;
    }
    for (int i = 0; i < 128; i++) {
        if (num[i] % 2 == 1) cnt1++;
        else if (num[i] != 0 && num[i] % 2 == 0) cnt0++;
    }
    if (cnt1 > 1 && len != 1) return false;
    return true;
}