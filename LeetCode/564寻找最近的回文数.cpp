#define MAX_STR_LEN 32

void reverseStr(char * str) {
    int n = strlen(str);
    for (int l = 0, r = n-1; l < r; l++, r--) {
        char c = str[l];
        str[l] = str[r];
        str[r] = c;
    }
}

long * getCandidates(const char * n, int * returnSize) {
    int len = strlen(n);
    int pos = 0;
    long * candidates = (long *)malloc(sizeof(long) * 5);
    candidates[pos++] = (long)pow(10, len - 1) - 1;
    candidates[pos++] = (long)pow(10, len) + 1;
    char str[MAX_STR_LEN], prefix[MAX_STR_LEN];
    char candidate[MAX_STR_LEN];
    snprintf(str, (len + 1) / 2 + 1, "%s", n);
    long selfPrefix = atol(str);    
    for (long i = selfPrefix - 1; i <= selfPrefix + 1; i++) {
        sprintf(prefix, "%ld", i);
        sprintf(candidate, "%s", prefix);
        reverseStr(prefix);
        sprintf(candidate + strlen(candidate), "%s", prefix + (len & 1));
        candidates[pos++] = atol(candidate);
    }
    *returnSize = pos;
    return candidates;
}

char * nearestPalindromic(char * n){
    long selfNumber = atol(n), ans = -1;
    int candidatesSize = 0;
    const long * candidates = getCandidates(n, &candidatesSize);
    for (int i = 0; i < candidatesSize; i++) {
        if (candidates[i] != selfNumber) {
            if (ans == -1 ||
                labs(candidates[i] - selfNumber) < labs(ans - selfNumber) ||
                labs(candidates[i] - selfNumber) == labs(ans - selfNumber) && candidates[i] < ans) {
                ans = candidates[i];
            }
        }
    }
    char * str = (char *)malloc(sizeof(char) * MAX_STR_LEN);
    sprintf(str, "%ld", ans);
    free(candidates);
    return str;
}