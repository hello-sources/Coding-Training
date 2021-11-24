//构造一个桶，然后分别顺序逆序遍历桶即可
char * sortString(char * s){
    int num[26] = {0};
    for (int i = 0; i < strlen(s); i++) {
        num[s[i] - 'a']++;
    }
    char *ans = (char *)malloc(sizeof(char) * (strlen(s) + 1));
    int cnt = 0;
    while (cnt < strlen(s)) {
        for (int i = 0; i < 26; i++) {
            if (num[i]) {
                ans[cnt++] = i + 'a';
                num[i]--;
            }
        }
        for (int i = 25; i >= 0; i--) {
            if (num[i]) {
                ans[cnt++] = i + 'a';
                num[i]--;
            }
        }
    }
    ans[cnt] = 0;
    return ans;
}