bool buddyStrings(char * s, char * goal){
    int len1 = strlen(s), len2 = strlen(goal);
    int count = 0;
    int temp[3] = {1, 2, 3};
    if (len1 != len2) return false;
    for (int i = 0; i < len1; i++) {
        if (s[i] != goal[i]) temp[count++] = i;
        if (count > 2) return false;
    }
    if (count == 1) return false;
    if (count == 2 && s[temp[0]] == goal[temp[1]] && s[temp[1]] == goal[temp[0]]) return true;
    else if (count == 0) {
        for (int i = 0; i < len1; i++) {
            for (int j = i + 1; j < len1; j++) {
                if (s[i] == s[j]) return true;
            }
        }
    }
    return false;
}