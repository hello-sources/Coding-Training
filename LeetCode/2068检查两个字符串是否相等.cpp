bool checkAlmostEquivalent(char * word1, char * word2){
    int ans[26] = {0};
    int ans1[26] = {0};
    for (int i = 0; word1[i]; i++) {
        ans[word1[i] - 'a']++;
    }
    for (int i = 0; word2[i]; i++) {
        ans1[word2[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (abs(ans[i] - ans1[i]) > 3) return false;
    }
    return true;
}