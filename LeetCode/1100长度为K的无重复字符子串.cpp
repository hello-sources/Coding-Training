int numKLenSubstrNoRepeats(char * s, int k){
    int len = strlen(s), cnt = 0, left = 0, right = -1;
    int hash[128] = {0};
    while (left < len) {
        if (right + 1 < len && hash[s[right + 1]] == 0) {
            hash[s[++right]]++;
        } else hash[s[left++]]--;
        if (right - left + 1 == k) {
            cnt++;
            hash[s[left++]]--;
        }
    }
    return cnt;
}