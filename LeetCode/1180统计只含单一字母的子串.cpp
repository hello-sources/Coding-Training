int countLetters(char * s){
    int ans = 0, cnt = 1;
    for (int i = 1; i < strlen(s); i++) {
        if (s[i] == s[i - 1]) cnt++;
        else {
            ans += (cnt * (cnt + 1)) / 2;
            cnt = 1;
        }
    } 
    ans += (cnt * (cnt + 1)) / 2;
    return ans;
}