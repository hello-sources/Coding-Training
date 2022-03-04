long long Hash(char *s, int l, int r) {
    unsigned long long val = 0;
    for (int i = l; i < r; i++) {
        val *= 2333;
        val += s[i] - 'a' + 1;
    }
    return val;
}

bool calc(long long *res, int size, long long x) {
    for (int i = 0; i < size; i++) {
        if (res[i] == x) return true;
    }
    return false;
}

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    long long res[wordDictSize + 1];
    for (int i = 0; i < wordDictSize; i++) {
        res[i] = Hash(wordDict[i], 0, strlen(wordDict[i]));
    }
    int len = strlen(s);
    bool dp[len + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = true;
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && calc(res, wordDictSize, Hash(s, j, i))) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[len];
}