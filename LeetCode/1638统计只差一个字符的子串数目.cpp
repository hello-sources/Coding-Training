int countSubstrings(char * s, char * t){
    int lens = strlen(s), lent = strlen(t), ans = 0;
    for (int i = 0; i < lens; i++) {
        for (int j = 0; j < lent; j++) {
            int dif = 0;
            for (int k = 0; i + k < lens && j + k < lent; k++) {
                dif += (s[i + k] != t[j + k]);
                if (dif > 1) break;
                if (dif == 1) ans++;
            }
        }
    }
    return ans;
}