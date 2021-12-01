bool areAlmostEqual(char * s1, char * s2){
    if (strcmp(s1, s2) == 0) return true;
    int len = strlen(s2), cnt = 0;
    char ind1, ind2;
    for (int i = 0; i < len; i++) {
        if (s1[i] == s2[i]) continue;
        if (cnt == 0) {
            ind1 = s1[i];
            ind2 = s2[i];
        } else if (cnt == 1) {
            if (ind1 != s2[i] || ind2 != s1[i]) return false;
        } else if (cnt > 1) {
            return false;
        }
        cnt++;
    }
    return cnt != 1;
}