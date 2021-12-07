int minTimeToType(char * word){
    int cnt = 0, len = strlen(word), flag;
    if (len == 1) return 1;
    flag = word[0] == 'a' ? 0 : fmin(word[0] - 'a', 26 - (word[0] - 'a'));
    for (int i = 1; i < len; i++) {
        int ind1 = word[i] - 'a';
        int ind2 = word[i  -1] - 'a';
        int calc = fmin(abs(ind1 - ind2), 26 - abs(ind1 - ind2));
        cnt += calc;
    }
    return cnt + len + flag;
}