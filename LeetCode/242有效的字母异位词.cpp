bool isAnagram(char * s, char * t){
    int cnt1[32], cnt2[32];
    int lens = strlen(s), lent = strlen(t);
    if (lens != lent) return false;
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    for (int i = 0; i < lens; i++) {
        cnt2[t[i] - 'a']++;
        cnt1[s[i] - 'a']++;
    }
    for (int i = 0; i < 32; i++) {
        if (cnt1[i] != cnt2[i]) return false;
    }
    return true;
}  