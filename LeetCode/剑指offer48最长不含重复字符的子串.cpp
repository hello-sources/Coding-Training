int lengthOfLongestSubstring(char * s){
    if (s == NULL) return 0;
    int hash[128] = {0};
    int left = 0, max = 0, ind;
    for (ind = 0; s[ind]; ind++) {
        if (left < hash[s[ind]]) {
            if (ind - left > max) max = ind - left;
            left = hash[s[ind]];
        }
        hash[s[ind]] = ind + 1;
    }
    if (ind  - left > max) max = ind - left;
    return max;
} 