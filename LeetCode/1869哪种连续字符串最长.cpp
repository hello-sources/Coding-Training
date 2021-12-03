bool checkZeroOnes(char * s){
    int cnt1 = 0, cnt0 = 0, len = strlen(s);
    for (int i = 0; s[i]; ) {
        if (s[i] == '1') {
            int cnt = 0;
            while (i < len && s[i] == '1') {
                i++;
                cnt++;
            }
            cnt1 = fmax(cnt, cnt1);
        } else if (s[i] == '0') {
            int cnt = 0;
            while (i < len && s[i] == '0') {
                i++;
                cnt++;
            }
            cnt0 = fmax(cnt, cnt0);
        }
    }
    return cnt1 > cnt0;
}